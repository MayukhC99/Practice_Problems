/*
*
*Problem Link : https://atcoder.jp/contests/dp/tasks/dp_s
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

/*
* we require 3 states in this digit-dp question: position,tight and sum
*/
const lld mod = 1e9 + 7;
const lld N= 10005;
lld dp[N][2][105];
string k;
lld d;

lld solve(lld pos,bool tight,lld sum){
	if(pos == k.length())
		return sum==0 ;
	if(dp[pos][tight][sum] != -1)
		return dp[pos][tight][sum];
		
	lld ans= 0;
	lld end= ((tight)? (k[pos]-'0') : 9);
	
	for(lld i=0; i<=end ; i++){
		
		ans= (ans + solve(pos+1 , tight&(i==end) , (sum+i)%d) ) % mod;
	}
	
	return dp[pos][tight][sum] = ans;
	
	
}


int main(){
	
	speed;boost;
	
	cin>>k;
	cin>>d;
	
	
	memset(dp,-1,sizeof dp);
	cout<<( solve(0,1,0) - 1  + mod) % mod;//0 will also be calculated. So, we are decreasing the solution by 1.
	
	return 0;
}


