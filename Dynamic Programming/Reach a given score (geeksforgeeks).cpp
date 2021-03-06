/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/reach-a-given-score/0
*Platform: geeksforgeeks
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
#define pii pair<lld,lld>
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

#define mod 1000000007
const lld inf= 1e12;

using namespace std;


int main(){
	speed;
	
	lld T;
	cin>>T;
	
	lld dp[1002] ;
	memset(dp,0,sizeof dp);
	dp[0] = 1;
	
	vector<lld> cases;
	lld mx = INT_MIN;
	for(lld i=0; i<T; i++){
		lld x;
		cin>>x;
		mx = max( mx , x );
		cases.pb(x);
	}
	
	
	//mx now contains the maximum number
	//we will for all possible combination uptill mx such that we can do it in one go
	for(lld i=3; i<=mx; i++)
		dp[i]+= dp[i-3];
	for(lld i=5; i<=mx; i++)
		dp[i]+= dp[i-5];
	for(lld i=10; i<=mx; i++)
		dp[i]+= dp[i-10];
		
	
	for(lld i=0 ; i<T; i++)
		cout<< dp[ cases[i] ] << endl;
	
	
	return 0;
}


