#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	lld n,k;
	cin>>n>>k;
	
	lld ar[n];
	F(ar,n);
	
	lld cum[n];
	cum[0]=ar[0];
	for(lld i=1;i<n;i++)
		cum[i]= cum[i-1]+ar[i];
		
	lld min_ix= 0;
	lld min_nu= cum[k-1];
	
	for(lld i=1;i<=n-k;i++){
		
		lld temp=(cum[i+k-1]-cum[i-1]);
		
		if( temp<min_nu ){
			min_nu= temp;
			min_ix= i;
		}
	}
	
	cout<<(min_ix+1);
	
	return 0;
}

