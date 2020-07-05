/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/coin-change/0
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

lld dp[1000][303];
int size;
int N;
int ar[100001];

lld solve(int i , int n){
	if(n == 0)
		return 1;
	if(n < 0 || i < 0)
		return 0;
	if(dp[i][n] != -1)
		return dp[i][n];
	if(ar[i] <= n)
		return dp[i][n] = solve(i , n-ar[i]) + solve(i-1 , n);
	else
		return dp[i][n] = solve(i-1 , n);
}

int main(){
	speed;
	
	int T;
	cin >> T;
	while(T--){
		cin >> size;
		F(ar , size);
		cin >> N;
		memset(dp , -1 , sizeof dp);
		cout << solve(size-1 , N) << endl;
	}
	return 0;
}


