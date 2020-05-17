/*
* 
*Problem Link : https://leetcode.com/problems/jump-game-v/
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
    int maxJumps(vector<int>& arr, int d) {
        vector<pair<int,int> > vec;
        
        for(int i=0;i<arr.size();i++){
            
            vec.push_back({arr[i],i});
        }
        
        int n=arr.size();
        
        if(n==1){
            return 1;
        }
        
        sort(vec.begin(),vec.end());
        vector<int> dp(vec.size());  
        
        dp[vec[0].second]=1;
        
        for(int i=1;i<vec.size();i++){
            
            int h=vec[i].first;
            int in=vec[i].second;
            int ma=1;
            
            for(int j=in+1;j<=min(n-1,(in+d));j++){  
                if(arr[j]<h){
                    ma=max(ma,1+dp[j]);
                }
                else{
                    break;
                }
            }
            for(int j=in-1;j>=max(0,in-d);j--){
                if(arr[j]<h){
                    ma=max(ma,1+dp[j]);
                }
                else{
                    break;
                }
            }
            dp[in]=ma;
        }
        
        return *max_element(dp.begin(),dp.end());
    }
};



