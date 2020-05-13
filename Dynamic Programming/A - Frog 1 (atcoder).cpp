/*
*
*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_a
*Platform: atcoder
*Status: Correct
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
	
	
	int N;
	cin>>N;
	
	vector<int> ar(N);
	F(ar,N);
	
	vector<int> dp(N,INT_MAX);
	
	dp[0]=0;//first stone we have to step
	
	for(int i=0; i<N-1; i++){
		
		if(i+1 < N)
			dp[i+1]= min(dp[i+1], dp[i] + abs(ar[i+1]-ar[i]) );
		if(i+2 < N)
			dp[i+2]= min(dp[i+2], dp[i] + abs(ar[i+2]-ar[i]) );
		
	}
	
	cout<<dp[N-1];
	
	return 0;
}


