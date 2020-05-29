/*
*
*Comment: It's a basic Dp question and is important for the inteviews 
*Problem Link : https://www.geeksforgeeks.org/maximum-profit-sale-wines/
*Platform: Mayukh's Computer :)
*Status: Correct
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

const int siz= 1000;

int dp[siz+1][siz+1];
int wine[siz];

//Top-Down approach
int solve(int b,int e,int y,int n){
	
	if(dp[b][e] != -1)
		return dp[b][e];
	if(y>n)
		return 0;
	if(b>e)
		return 0;
	
	int left= ( wine[b] * y ) + solve(b+1 , e , y+1 , n);
	int right= ( wine[e] * y ) + solve(b , e-1 , y+1 , n);
	
	//int m= max(left,right);
	//return m; //without dp
	
	dp[b][e]= max( left , right); //with dp
	
	return dp[b][e];
	
}

int main(){
	
	int n;
	cin>>n;
	
	F(wine,n);
	memset(dp, -1 , sizeof dp);
	solve(0 , n-1 , 1 , n);
	
	cout<<dp[0][n-1];
	
	return 0;
}


