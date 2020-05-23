/*
*
*Problem Link : https://leetcode.com/problems/three-equal-parts/
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
    vector<int> threeEqualParts(vector<int>& A) {
    	
        int num1s=0;
        
        for(int i:A) {
            if(i==1)
                num1s++;
        }
        
        if(num1s%3!=0)
            return {-1,-1};
        
        if(num1s==0)
            return {0,(int)A.size()-1};
        int c=num1s/3;
        
        vector<int> nums(3,0);
        int count=0;
        
        for(int i=0;i<A.size();i++) {
            
            if(A[i]==1) {
                if(count%c==0) {
                    nums[count/c]=i;  
                }
                count++;
            } 
        }
        
        while(nums[2]!=A.size()) { 
		  
            if(A[nums[0]]!=A[nums[1]] || A[nums[0]]!=A[nums[2]])
                return {-1,-1};
            nums[0]++;
            nums[1]++;
            nums[2]++;
        }
        
        return {nums[0]-1, nums[1]};
    }
};


