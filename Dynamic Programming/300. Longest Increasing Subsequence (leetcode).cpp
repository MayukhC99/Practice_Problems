/*
*
*Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/
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

//Top-Down approach

class Solution {
	
    int **dp;
    long long solve(vector<int>&nums , int n , int prev , int pi){
        if(n < 0)
            return 0;
        if(dp[n][pi] != -1)
            return dp[n][pi];
        if(nums[n] < prev)
            return dp[n][pi] = max( 1 + solve(nums , n-1 , nums[n] , n) , solve(nums , n-1 , prev , pi));
        else
            return dp[n][pi] = solve(nums , n-1 , prev , pi);
    }
    
    
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //alocating memory for dp array
        dp = new int*[n+1];
        for(int i = 0; i < n+1; ++i)
            dp[i] = new int[n+1];
        
        //initializing dp array
        for(int i=0 ; i<n+1 ; i++)
            for(int j=0 ; j<n+1 ; j++)
                dp[i][j] = -1;
        
        return solve(nums , n-1 , INT_MAX , n);
    }
};


