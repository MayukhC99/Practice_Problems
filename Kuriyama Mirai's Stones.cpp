#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	speed;
	boost;
	booster;
	
	lld n;
	cin>>n;
	lld ar[n];
	
	F(ar,n);
	
	lld m;
	cin>>m;
	
	lld cum[n];
	cum[0]=ar[0];
	for(lld i=1;i<n;i++)
		cum[i]=cum[i-1]+ar[i];
	
	sort(ar,ar+n);
	lld cum_sort[n];
	cum_sort[0]=ar[0];
	for(lld i=1;i<n;i++)
		cum_sort[i]=cum_sort[i-1]+ar[i];
		
	while(m--){
		lld type,l,r;
		cin>>type>>l>>r;
		l--;r--;
		
		if(type==1){
			if(l==0)
				cout<<cum[r]<<endl;
			else
				cout<<(cum[r]-cum[l-1])<<endl;
		}
		else {
			if(l==0)
				cout<<cum_sort[r]<<endl;
			else
				cout<<(cum_sort[r]-cum_sort[l-1])<<endl;
		}
	}
	
	return 0;
}

