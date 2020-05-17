/*
*
*Problem Link : https://www.codechef.com/CY302020/problems/CODY303
*Platform: codechef
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
	
	speed;boost;
	
	lld T;
	cin>>T;
	
	while(T--){
		lld N,M;
		cin>>N>>M;
		
		lld ar[N];
		F(ar,N);
		
		lld dp[N][M+1];
		
		//first we have to manually fillup first row
		dp[0][0]= 1;
		for(int i=1; i<=M ; i++)
			if(i==ar[0])
				dp[0][i]=1;
			else
				dp[0][i]=0;
		
		for(lld i=1; i<N ; i++){
			for(lld j=0; j<=M ; j++){
				
				if(j==0){
					dp[i][j]=1;
					continue;
				}
				
				if(ar[i] > j)
					dp[i][j]= dp[i-1][j];
				else
					dp[i][j]= dp[i-1][j] + dp[i-1][j - ar[i]];
			}
		}
		
		//PNF(dp,N,M+1);
		cout<<dp[N-1][M]<<endl;
	}
	
	
	return 0;
}


