/*
*
*Problem Link : https://leetcode.com/problems/coin-change-2/
*Platform: leetcode
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

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n= coins.size();
        int dp[n+1][amount+1];
        
        for(int i=0; i<=n ; i++)
            dp[i][0]= 1;
        for(int i=1; i<=amount ; i++)
            dp[0][i]= 0;
        
        for(int i=1; i<=n ; i++){
            
            for(int j=1; j<=amount ; j++){
                
                if(j < coins[i-1])
                    dp[i][j]= dp[i-1][j];
                else {
                    dp[i][j]= dp[i-1][j] + dp[i][j - coins[i-1]];
                }
            }
        }
        
        return dp[n][amount];
        
    }
};


