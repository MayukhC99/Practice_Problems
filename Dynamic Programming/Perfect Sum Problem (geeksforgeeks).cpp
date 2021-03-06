/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/perfect-sum-problem/0
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


lld dp[1005][1005];
lld a[1005];
lld N;

lld solve(lld n , lld sum){
	if( sum == 0 )
		return 1;
	if(sum < 0 || n < 0)
		return 0;
	if( dp[n][sum] != -1 )
		return dp[n][sum];
	
	if(a[n] <= sum)
		return dp[n][sum] =( ( solve( n-1 , sum-a[n] ) %mod) + (solve( n-1 , sum ) %mod) )%mod; 
	/*
	* for the above case we are finding conbination by including this number
	* and also by not including this number.
	*/
	else if(a[n] > sum)
		return dp[n][sum] = solve( n-1 , sum )%mod;
	
}


int main(){
	speed;
	
	lld T;
	cin >> T;
	while( T-- ){
		cin >> N;
		F(a , N);
		lld sum;
		cin >> sum;
		memset(dp , -1 , sizeof dp);
		cout << solve(N-1 , sum) << endl;
	}
	
	return 0;
}


