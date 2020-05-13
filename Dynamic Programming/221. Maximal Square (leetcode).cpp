/*
*
*Problem Link : https://leetcode.com/problems/maximal-square/
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
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        
        int row= matrix.size();
        int column= matrix[0].size();
        
        vector<vector<int>> dp(row+1 , vector<int>(column+1 ,0) );
        int largest=0;
        
        for(int i=1; i<=row ; i++){
            
            for(int j=1; j<=column ; j++){
                
                if(matrix[i-1][j-1]=='0')
                    dp[i][j]= 0;
                else {
                    
                    dp[i][j]= min(dp[i-1][j] , dp[i][j-1]);
                    dp[i][j]= 1 + min(dp[i][j] , dp[i-1][j-1]);
                    largest= max(largest , dp[i][j]);
                }
            }
        }
        
        return largest*largest; //we need to return the area
        
    }
};



