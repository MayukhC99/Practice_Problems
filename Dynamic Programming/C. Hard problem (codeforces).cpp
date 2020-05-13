/*
*
*Problem Link : https://codeforces.com/contest/706/problem/C
*Platform: codeforces
*Status: Incomplete
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
	
	speed;
	boost;
	
	lld N;
	cin>>N;//no of strings
	lld energy[N];
	F(energy,N); //array of energy
	vector<string> ar(N);
	F(ar,N);//vector of string
	
	vector<vector<lld>> dp(N,vector<lld>(2,INT_MAX));
	
	dp[0][0]= 0;
	dp[0][0]= 0;
	
	for(lld i=1; i<N; i++){
		
		if(ar[i]>=ar[i-1]){
			dp[i][0]= min(dp[i][0],dp[i-1][0]);
			dp[i][1]= min(dp[i][1],dp[i-1][1]);
		}
		else {
			
		}
	}
	
	
	
	
	return 0;
}

