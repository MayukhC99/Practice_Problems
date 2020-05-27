/*
*
*Problem Link : https://leetcode.com/problems/letter-case-permutation/
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
    vector<string> letterCasePermutation(string S) {
        int k= 0;
        map<int,int> mp;
        
        for(int i = 0 ; i < S.length() ; i++)
            if((S[i]-'0')>=0 && (S[i]-'0')<=9)
                continue;
            else
                mp[k++] = i ;
        
        
        vector<string> ans;
        for(int i = 0 ; i < (1<<k) ; i++){
            
            int dig= i;
            string temp = S;
            int pos= 0;
            int len= k;
            while(len--){
                int check= dig & 1;
                
                if(check)
                    temp[ mp[ pos ] ] = toupper( temp[ mp[ pos ] ] );
                else
                    temp[ mp[ pos ] ] = tolower( temp[ mp[ pos ] ] );
                
                pos++;
                dig>>= 1;
            }
            
            ans.push_back(temp);
        }
        
        
        return ans;
        
    }
};



