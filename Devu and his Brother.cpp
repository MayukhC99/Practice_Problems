#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(lld i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(lld i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	lld n,m;
	cin>>n>>m;
	
	lld a[n],b[m];
	
	F(a,n);
	F(b,m);
	
	sort(a,a+n);
	sort(b,b+m,greater<lld>());
	
	lld min_n= min(n,m);
	lld sum=0;
	
	for(lld i=0;i<min_n && b[i]>a[i];i++)
		sum+= (b[i]-a[i]);
		
		
	cout<<sum;
	
	return 0;
}


