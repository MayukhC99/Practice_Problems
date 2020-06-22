/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
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

/*
* This problem is a variation of lcs problem, 
* link : https://github.com/MayukhC99/Practice_Problems/blob/master/Dynamic%20Programming/1143.%20Longest%20Common%20Subsequence%20(leetcode).cpp
*/

string s;
lld N;
lld dp[1005][1005];

lld solve(lld n , lld m){
	if(n<0 || m<0)
		return 0;
	if(dp[n][m] != -1)
		return dp[n][m];
	if((s[n] == s[m]) && (n != m))
		return dp[n][m] = 1 + solve(n-1 , m-1);
	else
		return dp[n][m] = max(solve(n-1,m) , solve(n,m-1));	
}


int main(){
	speed;
	lld T;
	cin >> T;
	while(T--){
		cin >> N;
		cin >> s;
		memset(dp , -1 , sizeof dp);
		cout << solve(N-1 , N-1) << endl;
	}
	return 0;
}


