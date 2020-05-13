/*
*
*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_c
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

int main(){
	
	int N;
	cin>>N;
	
	vector<vector<int>> ar(N,vector<int>(3));
	NF(ar,N,3);
	
	vector<vector<int>> dp(N,vector<int>(3,-1));
	
	dp[0][0]= ar[0][0];
	dp[0][1]= ar[0][1];
	dp[0][2]= ar[0][2];
	
	for(int i=1; i<N; i++){
		for(int j=0; j<3; j++){
			
			for(int k=0; k<3; k++){
				if(k==j)continue;
				
				dp[i][j]= max(dp[i][j] , ar[i][j]+dp[i-1][k]);
			}
		}
	}
	
	cout<<max(dp[N-1][0], max(dp[N-1][1] , dp[N-1][2]) );
	
	return 0;
}
