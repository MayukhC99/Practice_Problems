/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/minimum-sum-partition/0
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


lld dp[100][10005];
lld N;
lld ar[100];

lld solve(int n , lld sum , lld rest){
	if(sum-rest <= 0)
		return abs(sum-rest);
	if( n < 0 )
		return abs(sum-rest);
	if( dp[n][sum] != -1 )
		return dp[n][sum];
	
	if( ar[n] <= sum )
		return dp[n][sum] = min( solve(n-1,sum-ar[n],rest+ar[n]) , solve(n-1,sum,rest) );
	else
		return dp[n][sum] = solve(n-1,sum,rest);
}


int main(){
	
	lld T;
	cin >> T;
	while(T--){
		cin >> N;
		F(ar , N);
		lld sum = 0;
		for(int i=0 ; i<N ; i++)
			sum+= ar[i];
		memset(dp , -1 , sizeof dp);
		cout << solve(N-1 , sum , 0) << endl;
	}
	
	return 0;
}


