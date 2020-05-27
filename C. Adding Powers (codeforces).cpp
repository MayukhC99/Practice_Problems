/*
*
*Problem Link : https://codeforces.com/problemset/problem/1312/C
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


int main() {
	
	speed;boost;

    ll n, m, num, tc, t = 1;

    cin>>tc;
    while (tc--) {
        cin>>num>>m;
        map<int,int> mpp;
        
        ll mxx = 0;
        for (ll i = 0; i < num; ++i) {
            
            
            cin>>n;
            ll pos = 0;
            while (n) {
                mpp[pos] += (n % m);
                n /= m;
                pos++;
            }
        }

        bool ok = true;
        for (auto inx : mpp) {
            if(inx.second > 1) {
                ok = false;
                break;
            }
        }

        if(ok == true) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

