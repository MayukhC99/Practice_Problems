/*
*
*Problem Link : https://leetcode.com/problems/cinema-seat-allocation/
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
    int numOfFamiliesCanArrange(uint8_t n) {
        if (n == 0) 
            return 2;
    
        if (n == 5 || n == 6 || n == 7 || n == 10 || n == 11 || n == 13 || n == 14 || n == 15)                 return 0;
        
        return 1;
    }
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        
        vector<uint8_t> p(1+(n>>1), 0);
        int total = 2 * n; 
        
        for (auto &s:reservedSeats) {
            
            if (s[1] == 1 || s[1] == 10) 
                continue;
            
            int r = s[0] - 1;
            uint8_t v = ((p[r>>1] >> (4*(r&1))) & 0xf);
            uint8_t nv = (v | (1 << ((s[1] - 2)>>1)));
            total -= (numOfFamiliesCanArrange(v) - numOfFamiliesCanArrange(nv));
            
            p[r/2] = (r&1) ? ((p[r>>1] & 0xf) | (nv << 4)) : ((p[r>>1] & 0xf0) | nv);
        }
        return total;
    }
};



