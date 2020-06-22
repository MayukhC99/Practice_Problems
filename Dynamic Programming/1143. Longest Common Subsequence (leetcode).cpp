/*
*
*Problem Link : https://leetcode.com/problems/longest-common-subsequence/
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
    int longestCommonSubsequence(string text1, string text2) {
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
        
        return dp[n][m];
    }
};


/*
* Bellow is the top down approach of the same problem.
* question link - https://practice.geeksforgeeks.org/problems/longest-common-subsequence/0
*/
/*
string x,y;
lld n,m;
lld dp[105][105];

lld solve(lld a, lld b){
	if(a<0 || b<0)
		return 0;
	if(dp[a][b] != -1)
		return dp[a][b];
	
	if(x[a] == y[b])
		dp[a][b] = 1 + solve(a-1,b-1) ; 
	else
		dp[a][b] = max(solve(a-1,b) , solve(a,b-1));
	
	return dp[a][b];
}


int main(){
	speed;
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		cin >> x ;
		cin >> y;
		memset(dp, -1 , sizeof dp);
		cout << solve(n-1 , m-1) << endl;
	}
	
	return 0;
}
*/


