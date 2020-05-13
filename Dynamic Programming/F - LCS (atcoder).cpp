/*
*
*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_f
*Platform: atcoder
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
    string longestCommonSubsequence(string text1, string text2) {
        int n= text1.length();
        int m= text2.length();
        
        vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
        
        for(int i=1; i<=n ; i++){
            
            for(int j=1; j<=m; j++){
                
                if(text1[i-1] == text2[j-1])
                    dp[i][j]= 1 + dp[i-1][j-1];
                else
                    dp[i][j]= max(dp[i-1][j] , dp[i][j-1]);
            }
        }
        
        //int len= dp[n][m];
        
        string s="";
        
        int i=n;
        int j=m;
        
        while (i > 0 && j > 0) 
   		{ 
      		// If current character in X[] and Y are same, then 
      		// current character is part of LCS 
      		if (text1[i-1] == text2[j-1]) 
      		{ 
         		s = text1[i-1] + s; // Put current character in result 
          		i--; j--;      // reduce values of i, j and index 
      		} 
  
      		// If not same, then find the larger of two and 
	    	// go in the direction of larger value 
      		else if (dp[i-1][j] > dp[i][j-1]) 
         		i--; 
      		else
         		j--; 
   		} 
		
		return s;
    }
};

int main(){
	
	speed;boost;
	
	string s;
	string t;
	cin>>s>>t;
	
	Solution res;
	
	cout<<res.longestCommonSubsequence(s,t);
	
	return 0;
}


