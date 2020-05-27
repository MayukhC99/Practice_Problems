/*
*
*Problem Link : https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
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

//using Sieve of Eratosthenes to generate all prime numbers between 1 and 32
class Solution {
    
    bool prime[33];
    
public:
    
    Solution(){
        memset(prime,false,sizeof prime);
        prime[1]= true;//ture means non prime and false means prime
        
        for(int i = 2 ; i*i <= 32 ; i++)
            if(!prime[i])
                for(int j = i*2 ; j <= 32 ; j+=i)
                    prime[j]= true;
        
    }
    
    int countPrimeSetBits(int L, int R) {
        int count=0;
        
        for( int i = L ; i <= R ; i++ )
            if( !prime[ __builtin_popcountll(i) ] )
                count++;
        
        return count;
    }
};



