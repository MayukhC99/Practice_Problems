/*
*
*Problem Link : https://leetcode.com/problems/target-sum/submissions/
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
    int findTargetSumWays(vector<int>& nums, int S) {
        
        if(nums.empty())
            return 0;
        
        int sum=0;
        int n= nums.size();
        for(int i=0; i<n ; i++)
            sum+= nums[i];
        
        int req=0;
        S= abs(S);
        
        if(sum<S || ((sum+S != 0) && (sum + S)%2 != 0))
            return 0;
        else if(sum+S != 0)
            req= (sum + S)/2;
        
        vector<vector<int>> dp(n+1,vector<int>(req+1,0));
        
        //doing the first row manually for 0
        dp[0][0]= 1;
        
        for(int i=1; i<=n; i++){
            
            for(int j=0; j<=req; j++){
                
                dp[i][j]= dp[i-1][j] + dp[i][j];
                    
                if(nums[i-1]+j <= req)
                    dp[i][nums[i-1] + j]= dp[i][nums[i-1] + j] + dp[i-1][j];
                
            }
        }
        
        //check the table
        // for(int i=1; i<n; i++){
        //     for(int j=0; j< req; j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return dp[n][req];
    }
};


