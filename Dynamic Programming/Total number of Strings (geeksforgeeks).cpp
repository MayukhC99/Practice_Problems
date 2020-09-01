/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/total-number-of-strings/0
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


lld dp[100][5][5];

lld solve(int n , int b , int c){
    if(b<0 || c<0)
        return 0;
    if(n==0)
        return 1;
    if(dp[n][b][c] != -1)
        return dp[n][b][c];
    return dp[n][b][c] = solve(n-1,b,c) + solve(n-1,b-1,c) + solve(n-1,b,c-1);
}


int main() {
	int T;
	cin >> T;
	memset(dp, -1 , sizeof dp);
	
	while(T--){
	    int N;
	    cin >> N;
	    
	    cout << solve(N,1,2) << endl;
	}
	return 0;
}


