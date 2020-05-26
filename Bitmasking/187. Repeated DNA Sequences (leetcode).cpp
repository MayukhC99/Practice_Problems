/*
*
*Problem Link : https://leetcode.com/problems/repeated-dna-sequences/
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
    
    int char_to_bit(char c){
        if(c=='A') return 0;
        if(c=='C') return 1;
        if(c=='G') return 2;
        if(c=='T') return 3;
        return 0;
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        
        int n= s.size(), mask=0, bitmask=(1<<20)-1;
        if(n==0) return {};
        unordered_map<int, int> ht;
        vector<string> result;
        
        for(int i=0; i<10; i++){
            mask= (mask<<2) | char_to_bit(s[i]);
        }
        
        ht[mask]++;
        
        for(int i=10; i<n; i++){
            mask= ((mask<<2) & bitmask) | char_to_bit(s[i]);
            if(ht.find(mask)!=ht.end() && ht[mask]==1)
                result.push_back(s.substr(i-9, 10));
            ht[mask]++;
        }
        
        
        return result;
        
    }
};


