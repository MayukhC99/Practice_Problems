/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0
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

lld dp[1005][2][3];

lld solve(int n , int bcount=1 , int ccount=2){
	
	if(bcount<0 || ccount<0)
		return 0;
	if(n == 0)
		return 1;
	if(bcount==0 && ccount==0)
		return 1;
	if(dp[n][bcount][ccount] != -1)
		return dp[n][bcount][ccount] ;
	
	/*
	* recurse for 3 cases : only len decrease denoting a, 
	* len decreases along with b, 
	* len decreases along c
	*/
	dp[n][bcount][ccount] = solve(n-1,bcount,ccount) + solve(n-1,bcount-1,ccount) + solve(n-1,bcount,ccount-1);
	
	return dp[n][bcount][ccount] ;
}

int main(){
	speed;
	memset(dp , -1 , sizeof dp);
	
	int T;
	cin >> T;
	while(T--){
		int N;
		cin >> N;
		cout << solve(N) << endl;
	}
	
	return 0;
}


