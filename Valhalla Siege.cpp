#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

typedef long long int lld;

using namespace std;


int main(){
	speed;
	boost;
	
	lld n,q;
	cin>>n>>q;
	
	lld iv[n],l[q];
	
	F(iv,n);
	F(l,q);
	
	lld cum[n];
	cum[0]=iv[0];
	for(int i=1;i<n;i++)
		cum[i]= cum[i-1]+iv[i];
		
	
	lld sum= 0;
	lld beg=0;
	
	for(int i=0;i<q;i++){
		
		auto itr = upper_bound(cum+beg,cum+n,l[i]+sum);
		beg= (lld)(itr-cum);
		sum+=l[i];
		
		if(beg>=n){
			sum=0;
			beg=0;
			cout<<n<<endl;
			continue;
		}
		
		cout<<(n-beg)<<endl;
	}
	
	return 0;
}

