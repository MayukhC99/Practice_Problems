/*
*
*Problem Link : https://app.codesignal.com/interview-practice/task/7o2Aba2Zep3MJPKQ3
*Platform: codesignal
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


long long int dp[100005];
const long long int mod = 1000000007;

int solve(int i,string& s){
    if(i == s.length())
        return 1;
    if(i > s.length())
        return 0;
    if(dp[i] != -1)
        return dp[i];
    
    long long int ans = 0;
    if(i < s.length()-1){
        int num = (s[i]-'0')*10 + (s[i+1]-'0');
        if((num <= 26) && (s[i] != '0'))
            ans = solve(i+2 , s)%mod;
        
        if(s[i] != '0')
            ans= ((ans%mod) + (solve(i+1 , s)%mod))%mod;
    }
    else if(s[i] != '0')
        ans = solve(i+1 , s)%mod;
    
    return dp[i] = ans%mod;
    
}

int mapDecoding(std::string message) {
    memset(dp , -1 , sizeof dp);
    return solve(0 , message);
}


