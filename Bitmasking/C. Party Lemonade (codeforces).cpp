/*
*
*Problem Link : https://codeforces.com/problemset/problem/913/C
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


ll dp[35];

int main() {
    speed;boost;

    int i, j, k;
    int n, m, L;

    cin>>n>>L;
    F(dp,n);

    for(i = 1; i < n; i++)
        dp[i] = min(dp[i], 2 * dp[i - 1]);

    ll ans = 4e18;
    ll sum = 0;

    for(i = n - 1; i >= 0; i--){
    	
        k = L / (1 << i);
        sum += (ll)k * dp[i];
        L -= (1 << i) * k;
        ans = min(ans, sum + (L > 0) * dp[i]);
    }

    cout << ans;

    return 0;
}


