/*
*
*Problem Link : https://leetcode.com/problems/minimum-number-of-taps-to-open-to-water-a-garden/
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
    int minTaps(int n, vector<int>& ranges) {
        
        vector<pair<int,int>> v;
        
        for (int i = 0; i < n + 1; i++) {
            
            if (ranges[i])
                v.emplace_back(max(i - ranges[i], 0), min(i + ranges[i], n));
        }
        
        if (v.empty()) 
            return -1;
        
        sort(v.begin(), v.end());
        int m = v.size(), p = 0;
        int end = 0, ans = 0;
        
        while (end < n) {
            
            int t = end;
            while (p < m) {
                
                if (v[p].first > end) break;
                if (end >= v[p].first && end < v[p].second)
                    t = max(t, v[p].second);
                p++;
            }
            if (t == end) 
                return -1;
            end = t;
            ans++;
        }
        
        
        return ans;
    }
};


