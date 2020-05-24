/*
*
*Problem Link : https://codeforces.com/contest/802/problem/B
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


int n,k,a[400001],ans,next_occur[400001],last_occur[400001],inf=1e9;
set<int>s;

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=n-1;i>=0;--i)
    {
        if(!last_occur[a[i]])
        {
            next_occur[i]=inf;
            last_occur[a[i]]=i;
        }
        else
        {
            next_occur[i]=last_occur[a[i]];
            last_occur[a[i]]=i;
        }
    }
    for(int i=0;i<n;++i)
    {
        if(s.count(i))
            s.erase(i);
        else
        {
            if(s.size()==k)
                s.erase(--s.end());
            ++ans;
        }
        s.insert(next_occur[i]);
    }
    cout<<ans;
    
    return 0;
}


