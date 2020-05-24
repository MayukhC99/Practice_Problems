/*
*
*Problem Link : https://leetcode.com/problems/longest-happy-string/
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
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, int>> pq;
        
        if(a>0)
            pq.push({a, 'a'});
        if(b>0)
            pq.push({b, 'b'});
        if(c>0)
            pq.push({c, 'c'});
        
        string ans="";
        
        while(!pq.empty()){
            
            int c1=pq.top().first;
            char ch1=pq.top().second;
            pq.pop();
            ans+=string(min(c1,2),ch1);
            c1-=min(c1,2);
            
            if (!pq.empty()) {
                
                int c2=pq.top().first;
                char ch2=pq.top().second;
                pq.pop();
                if (c2>c1) {
                    
                    ans+=string(min(c2,2),ch2);
                    c2-=min(c2,2);
                }
                else {
                    
                    ans+=ch2;
                    c2--;
                }
                
                if (c2>0)
                    pq.push(make_pair(c2, ch2));
                if (c1>0) 
                    pq.push(make_pair(c1, ch1));
            }
        }
        
        return ans;     
    }
};


