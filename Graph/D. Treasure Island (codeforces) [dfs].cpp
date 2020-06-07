/*
*
*Problem Link : https://codeforces.com/problemset/problem/1214/D
*Platform: codeforces
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;
 
ll n, m;
vector<vector<bool>> ok;
 
bool dfs(ll i = 0, ll j = 0) {
	if (i >= n || j >= m || !ok[i][j]) return false;
	if (i == n-1 && j == m-1) return true;
	ok[i][j] = false;
	if (dfs(i+1, j)) return true;
	if (dfs(i, j+1)) return true;
	return false;
}
 
int main() {
	speed;boost;
	
	cin >> n >> m;
	ok.assign(n, vector<bool>(m));
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			char c;
			cin >> c;
			ok[i][j] = c == '.';
		}
	}
	ll res = 0;
	while (dfs()) {
		res++;
		ok[0][0] = true;
		ok[n-1][m-1] = true;
	}
	cout << res << endl;
	
	return 0;
}


