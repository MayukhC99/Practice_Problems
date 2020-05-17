/*
*
*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_h
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

const lld MOD= 1e9 + 7;

int main(){
	
	speed;boost;
	
	lld row,col;
	cin>>row>>col;
	vector<vector<char>> grid(row, vector<char>(col));
	NF(grid,row,col);
	
	vector<vector<lld>> dp(row, vector<lld>(col));
	
	bool flag= true;
	for(lld i=0; i<col ; i++)
		if(grid[0][i]=='.' && flag)
			dp[0][i]=1;
		else{
			dp[0][i]=0;
			flag=false;
		}
	
	flag= true;
	for(lld i=0; i<row ; i++)
		if(grid[i][0]=='.' && flag)
			dp[i][0]=1;
		else{
			dp[i][0]=0;
			flag= false;
		}
	
	for(lld i=1; i<row ; i++){
		
		for(lld j=1; j<col ; j++){
			
			if(grid[i][j]=='#')
				dp[i][j]= 0;
			else
				dp[i][j]= ( dp[i-1][j] + dp[i][j-1] ) % MOD;
		}
	}
	
	cout<<dp[row-1][col-1];
	
	return 0;
}


