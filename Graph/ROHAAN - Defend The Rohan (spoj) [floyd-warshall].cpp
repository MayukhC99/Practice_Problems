/*
*
*Problem Link : https://www.spoj.com/problems/ROHAAN/
*Platform: spoj
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

#define mod 1000000007
#define inf 1e12

using namespace std;

int main(){
	speed;
	
	lld T;
	lld case_counter = 0;
	cin>>T;
	
	while(T--){
		case_counter++;
		
		lld N;
		cin>>N;
		lld dp[N+1][N+1];
		NF1(dp,N,N);
		
		for(lld k = 1 ; k<=N ; k++)
			for(lld i = 1 ; i<=N ; i++)
				for(lld j = 1 ; j<=N ; j++)
					dp[i][j] = min(dp[i][j] , dp[i][k] + dp[k][j] );
		
		lld ans = 0;
		lld R;
		cin>>R;
		for(lld i=0; i<R ; i++){
			lld x,y;
			cin>>x>>y;
			ans+= dp[x][y];
		}
		
		cout<<"Case #"<<case_counter<<": "<<ans<<endl;
		
	}
	
	
	return 0;
}


