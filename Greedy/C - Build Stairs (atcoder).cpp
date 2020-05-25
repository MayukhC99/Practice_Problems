/*
*
*Problem Link : https://atcoder.jp/contests/abc136/tasks/abc136_c
*Platform: atcoder
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;

int main(){
	
	speed;boost;
	
	lld N;
	cin>>N;
	lld ar[N+1];
	F(ar,N);
	
	ar[N]= INT_MAX;
	for(lld i=N-1; i >= 0; i--){
		if(ar[i] <= ar[i+1])
			continue;
		else if(ar[i]-1  <= ar[i+1])
			ar[i]-=1;
		else {
			cout<<"No";
			return 0;
		}
	}
	
	cout<<"Yes";
	
	return 0;
}



