/*
*
*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_n
*Platform: atcoder
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


const int ma = 500;
const ll INF = 1e18L + 5; // 10^18+5
ll dp[ma][ma];

ll sum(vector<int>& a, int Left, int Right) {
    ll sum = 0;
    for(int i = Left; i <= Right; ++i) {
        sum += a[i];
    }
    return sum;
};

int main() {
	//speed;boost;
	
    int n;
    cin>>n;
    vector<int> a(n);
    
    
    F(a,n); //taking array inputs
    
    
    for(int i = n-1; i >= 0; i--) {
        for(int j = i; j < n ; j++) {
            if(i == j) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = INF;
                ll s = sum(a, i, j);
                for(int k = i; k <= j-1; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + s);
                }
            }
        }
    }
    
    cout<<dp[0][n-1];
}

