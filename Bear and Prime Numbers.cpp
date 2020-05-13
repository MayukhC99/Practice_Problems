#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<" ";}

#define Max 10000001

using namespace std;

void SieveOfEratosthenes(lld n,lld count[],lld pre[],lld temp) 
    { 
        
        bool prime[n+1]; 
        memset(prime, true, sizeof(prime)); 
  
        for (lld p=2; p*p<=n; p++) 
        { 
        
            if (prime[p] == true) 
            { 
             
                for (lld i=p*p; i<=n; i += p) 
                    prime[i] = false; 
            } 
        } 
  
        for (lld p=2; p<=n; p++) {
            if (prime[p]) {
            	for(lld i=p;i<=temp;i=i+p){
            		//cout<<"for prime "<<p<<" = ";
            		pre[p]+= count[i];
				}
				//cout<<pre[p]<<endl;
			}
    	}
                 
        
    } 

int main(){
	speed;
	boost;
	booster;
	
	lld n,m;
	cin>>n;
	
	lld count[Max];
	lld pre[Max];
	
	for(lld i=0;i<Max;i++)
		count[i]= pre[i]= 0;
	
	lld max_temp=0;
	for(lld i=0;i<n;i++){
		lld temp;
		cin>>temp;
		count[temp]++;
		if(temp>max_temp)
			max_temp=temp;
	}
	
					//P(count,Max);
					//cout<<endl;
	
	SieveOfEratosthenes(Max,count,pre,max_temp);
	
	
					//P(pre,Max);
					//cout<<endl;
	
	pre[0]=0;
	for(lld i=1;i<Max;i++)
		pre[i]= pre[i-1]+pre[i];
	
	cin>>m;
	
	while(m--){
		lld l,r;
		cin>>l>>r;
		
		if(l>Max){
			cout<<"0"<<endl;
			continue;
		}
		
		if(r>Max)
			r=Max-1;
		
		cout<<(pre[r]-pre[l-1])<<endl;
		
	}
	
	return 0;
}

    
