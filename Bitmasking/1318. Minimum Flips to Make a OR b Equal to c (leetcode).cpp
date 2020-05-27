/*
*
*Problem Link : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
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
    int minFlips(int a, int b, int c) {
        bitset<32> aset(a);
        bitset<32> bset(b);
        bitset<32> cset(c);
        
        int count = 0 ;
        for(int i = 0 ; i < 32 ; i++ ){
            
            if( cset[i] == 0 ){
                
                if(aset[i] == 1)
                    count++;
                if(bset[i] == 1)
                    count++;
            }
            else {
                
                if( ( aset[i] == 1 ) || ( bset[i] == 1 ) )
                    continue;
                else
                    count++;
            }
                
        }
        
        return count;
    }
};



