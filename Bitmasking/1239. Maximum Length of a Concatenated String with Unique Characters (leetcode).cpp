/*
*
*Problem Link : https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
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
    
    int maxi = INT_MIN;
    
public:
    
    bool check(string& s){
        bitset<32> bit(0);
        int n= s.length();
        
        for(int i = 0 ; i < n ; i++){
            if(bit[ s[i] - 'a' ] == 1)
                return false;
            bit[ s[i] - 'a' ] = 1;
        }
        
        return true;
    }
    
    void solve(vector<string>& ar, string s, int i, int n){
        
        if( i >= n ){
            
            if((s != "") && check(s))
                maxi= max( maxi , (int)s.length() );
            return ;
        }
        
        solve(ar,s,i+1,n);
        
        s+= ar[i];
        
        solve(ar,s,i+1,n);
        
    }
    
    int maxLength(vector<string>& arr) {
        
        solve(arr,"",0,arr.size());
        return maxi == INT_MIN ? 0 : maxi;
    }
};





//The bellow approach will give TLE. But it can also be done in this way
/*class Solution {
    
    int maxi = INT_MIN;
    
public:
    
    bool check(string s){
        int bit=0xffffffff;
        
        for(int i = 0 ; i < s.length() ; i++){
            int b = 1 << ( ( s[i] - 'a' ) + 1);
            bit = bit ^ b ;
        }
        
        return (32 - __builtin_popcount(bit) ) == s.length();
    }
    
    void solve(vector<string>& ar, string s, int i, int n){
        
        if( i >= n ){
            
            if((s != "") && check(s))
                maxi= max( maxi , (int)s.length() );
            return ;
        }
        
        solve(ar,s,i+1,n);
        
        s+= ar[i];
        
        solve(ar,s,i+1,n);
        
    }
    
    int maxLength(vector<string>& arr) {
        
        solve(arr,"",0,arr.size());
        return maxi == INT_MIN ? 0 : maxi;
    }
};*/


