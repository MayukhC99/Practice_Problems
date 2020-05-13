/*
*
*Problem Link : https://leetcode.com/problems/delete-and-earn/submissions/
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
    int deleteAndEarn(vector<int>& nums) {
        int n= nums.size();
        if(n==0)
            return 0;
        
        vector<int> non_dup; //contains elements without duplicate
        map<int,int> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(auto it=mp.begin(); it!=mp.end(); it++)
            non_dup.push_back(it->first);
        
        n= non_dup.size();
        vector<int> dp(n,0);
        dp[0]= non_dup[0]*mp[non_dup[0]];
        if(n==1)
            return dp[0];
        
        dp[1]= non_dup[1]*mp[non_dup[1]];
        if(non_dup[1]-1 == non_dup[0])
            dp[1]= max(dp[0],dp[1]);
        else
            dp[1]+= dp[0];
        
        for(int i=2; i < non_dup.size() ; i++){
            
            dp[i]= non_dup[i]*mp[non_dup[i]];
            
            if(non_dup[i]-1 == non_dup[i-1])
                dp[i]= max(dp[i-1] , dp[i] + dp[i-2] );
            else
                dp[i]+=  dp[i-1];
        }
        
        return dp[n-1];
    }
};



