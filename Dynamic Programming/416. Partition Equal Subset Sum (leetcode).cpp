/*
*
*Problem Link : https://leetcode.com/problems/partition-equal-subset-sum/submissions/
*Platform: leetcode
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


class Solution {
    
    int dp[10000];
    bool solve(vector<int>& nums , int n, int sum){
        if(n < 0)
            return false;
        if(sum < 0)
            return false;
        if(sum == 0)
            return true;
        if(dp[sum] != -1)
            return dp[sum];
        
        if(nums[n] <= sum)
            return dp[sum] = solve(nums , n-1 , sum-nums[n]) || solve(nums, n-1 , sum);
        else
            return dp[sum] = solve(nums , n-1 , sum);
    }
    
public:
    bool canPartition(vector<int>& nums) {
        memset(dp , -1 , sizeof dp);
        int sum = 0;
        for(int x: nums)
            sum+= x;
        if(sum % 2 != 0)
            return false;
        else
            return solve(nums , nums.size()-1 , sum/2);
    }
};


