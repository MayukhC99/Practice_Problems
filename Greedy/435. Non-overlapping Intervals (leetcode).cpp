/*
*
*Problem Link : https://leetcode.com/problems/non-overlapping-intervals/
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1)
            return 0;
        
        sort(intervals.begin(),intervals.end(),[&](vector<int>& a,vector<int>& b){
            if(a[1]==b[1])
                return a[0]<b[0];
            else
                return a[1]<b[1];
        });
        
        int count=0;
        stack<vector<int>> q;
        q.push(intervals[0]);
        
        for(int i=1; i<intervals.size(); i++){
            
            if(intervals[i][0]<q.top()[1])
                count++;
            else
                q.push(intervals[i]);
        }
        
        
        return count;
    }
};



