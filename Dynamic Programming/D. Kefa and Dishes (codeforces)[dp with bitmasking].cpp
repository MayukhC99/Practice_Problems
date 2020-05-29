/*
*
*Problem Link : https://codeforces.com/problemset/problem/580/D
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


int const N = 19;
int n, m, k, a[N], b[N][N];
long long dp[(1 << N)][N];

long long rec(int msk, int lst, int cnt) {
	if(cnt > n)
		return -1e9;
	if(cnt == m)
		return 0;

	long long &ret = dp[msk][lst];
	if(ret != -1)
		return ret;
	ret = 0;

	for(int i = 0; i < n; ++i)
		if((msk & (1 << i)) == 0)
			ret = max(ret, rec(msk | (1 << i), i, cnt + 1) + a[i] + b[lst][i]);

	return ret;
}

int main() {
	speed;boost;
	
	cin>>n>>m>>k;
	
	for(int i = 0; i < n; ++i)
  		cin >> a[i];
  	for(int i = 0; i < k; ++i) {
  		
  		int from, to, sat;
  		cin>>from>>to>>sat;
  		--from, --to;
  		b[from][to] = sat;
  	}

  	memset(dp, -1, sizeof dp);
  
  	long long res = 0;
  	for(int i = 0; i < n; ++i)
  		res = max(res, rec((1 << i), i, 1) + a[i]);
  	
  	
  	cout<<res<<endl;

  	return 0;
}


