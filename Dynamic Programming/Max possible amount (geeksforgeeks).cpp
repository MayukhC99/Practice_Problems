/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/max-possible-amount/0
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

lld dp[101][101];
int N;
lld ar[101];

lld solve(int a , int b){
	if(a > b)
		return 0;
	if(dp[a][b] != -1)
		return dp[a][b];
	return dp[a][b] = max(ar[a]+min(solve(a+2 , b),solve(a+1 , b-1)) , ar[b]+min(solve(a , b-2),solve(a+1 , b-1)));
}


int main(){
	speed;
	
	int T;
	cin >> T;
	while(T--){
		cin >> N;
		F(ar , N);
		memset(dp , -1 , sizeof dp);
		cout << solve(0 , N-1) << endl;
	}
	
	return 0;
}


