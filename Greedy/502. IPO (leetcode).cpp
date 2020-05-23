/*
*
*Problem Link : https://leetcode.com/problems/ipo/
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
    int findMaximizedCapital(int k,int w,vector<int>& profit,vector<int>& cap) {
    	
        vector<pair<int,int>> v;                                           
        
        for(int i=0;i<cap.size();i++)
            v.push_back(make_pair(cap[i],profit[i]));
            
        sort(v.begin(),v.end());
        priority_queue<int> pq;                   
        int i=0;
        
        while(i<v.size() && k>0){
        	
            while(i<v.size() && v[i].first<=w){
            	
                pq.push(v[i].second);
                i++;
            }
            
            if(!pq.empty()){
            	
                w+=pq.top();
                pq.pop();
                k--;
            }
            
            else
                break;
        }
        
    
        while(k-- && !pq.empty()){
        	
            w+=pq.top();
            pq.pop();
        }
        
        return w;
    }
};


