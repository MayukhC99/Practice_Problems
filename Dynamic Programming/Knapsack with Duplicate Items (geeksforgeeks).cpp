/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items/0
*Platform: geeksforgeeks
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define booster cout.tie(NULL)
#define endl "\n"

typedef long long int lld;

#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define pii pair<lld,lld>
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

#define mod 1000000007
const lld inf= 1e12;

using namespace std;

lld dp[1003][1003];
lld wt[1003],val[1003];

lld solve(lld w,lld n){
	if( n == 0 || w == 0 ) //1 based indexing
		return 0;
	if( dp[n][w] != -1 )
		return dp[n][w];
	
	if(wt[n] <= w)
		return dp[n][w] = max( val[n] + solve(w-wt[n] , n)  , solve(w , n-1) );
	else if (wt[n] > w)
		return dp[n][w] = solve( w , n-1 );
	
}


int main(){
	speed;
	
	lld T;
	cin >> T;
	while( T-- ){
		lld N,W;
		cin >> N >> W;
		F1(val,N);
		F1(wt,N);
		memset(dp , -1 , sizeof dp);
		cout <<	solve(W,N) << endl;
	}
	
	return 0;
}


