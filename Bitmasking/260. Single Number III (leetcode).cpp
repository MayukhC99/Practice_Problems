/*
*
*Problem Link : https://leetcode.com/problems/single-number-iii/
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
    vector<int> singleNumber(vector<int>& nums) {
        
        /*
        *First we need to find the xor of all elements.
        *As we know xor of 2 equal number is 0.
        *We also know that xor of 2 numbers produces
        *0 for similar bits and 1 for dissimilar bits.
        *So ultimately after XORing all the elements,
        *the final value would contain dissimilar bits of
        *both the unique numbers.
        */
        int val=0;
        int n= nums.size();
        for(int i = 0 ; i < n ; i++ )
            val^= nums[i];
        
        /*
        *Now we would extract any set bit from val as 
        *this bit will be different for both the
        *unique numbers. Thus we extract the rightmost
        *bit.
        */
        val = val & (-val);
        
        /*
        *Now we will iterate again over nums and select all 
        *elements having the same bit as in val and xor them,
        *and also xor all elements which does not contain the
        *same bit as in val. This will give us both the unique
        *numbers.
        */
        
        vector<int> ans(2,0);
        for(int i = 0 ; i < n ; i++ ){
            
            if( nums[i] & val )
                ans[0]^= nums[i];
            else
                ans[1]^= nums[i];
        }
        
        
        return ans;
        
    }
};



