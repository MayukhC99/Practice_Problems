/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/gold-mine-problem/0
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

int dp[25][25];
int n,m;
int ar[25][25];

int solve(int i , int j){
	if(i < 0 || i >= n || j >= m)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];
	
	int cost = ar[i][j];
	int right = solve(i , j+1);
	int top_right = solve(i-1 , j+1);
	int down_right = solve(i+1 , j+1);
	 
	return dp[i][j] = cost + max(right , max(top_right , down_right));
}

int main(){
	speed;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		NF(ar , n , m);
		memset(dp , -1 , sizeof dp);
		int ans = -1;
		for(int i = 0 ; i < n ; i++)
			ans = max(ans , solve( i , 0 ));
		cout << ans << endl;
	}
	return 0;
}


