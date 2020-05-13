/*
*
*Problem Link : https://leetcode.com/problems/triangle/submissions/
*Platform: leetcode
*Status: Correct
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
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.empty())
            return 0;
        
        int n= triangle.size();
        int base= triangle[n-1].size();
        
        vector<vector<int>> dp(base,vector<int>(base,INT_MAX));
        
        dp[0][0]=triangle[0][0];
        
        for(int i=0; i<n-1 ; i++){
            
            for(int j=0; j<triangle[i].size() ; j++){
                
                dp[i+1][j]= min(dp[i+1][j] , dp[i][j] + triangle[i+1][j]);
                dp[i+1][j+1]= min(dp[i+1][j+1] , dp[i][j] + triangle[i+1][j+1]);
                
            }
            
        }
        
        
        return *min_element(dp[n-1].begin() , dp[n-1].end());
    }
};


