/*
*
*Problem Link : https://codeforces.com/problemset/problem/1036/C
*Platform: codeforces
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

lld dp[20][4][2];
/*
* This is a typical question of digit dp.
* We are considering 3 states. 20 for the "pos" whose value can range till 10^18,
* 4 for the "count" whose value can range till 3 as total number of non-zero number can be atmost 3
* 2 for the "tight" whose value is 1 if previous string is same and 0 if it's not
*/
lld L,R;
string s;

lld solve(lld pos , lld count , lld tight){
	
	if(pos==s.length())
		return 1;
	if( dp[pos][count][tight] != -1 )
		return dp[pos][count][tight];
		
	lld ans= 0;
	lld end= ( tight == 1 ) ? ( s[pos] - '0' ) : 9 ;
	
	for(lld i=0; i<=end ; i++){
		lld sub_count= count + (i>0);
		
		if( sub_count <= 3 ){
			
			ans= ans + solve(pos+1 , sub_count , tight & (i == end));
		}
		
	} 
	
	dp[pos][count][tight] = ans ;
	
	return ans;
	
}

int main(){
	speed;boost;
	
	lld T;
	cin>>T;
	
	while(T--){
		cin>>L>>R;
		lld ans;
		
		s= to_string(R);
		
		memset(dp,-1,sizeof dp);
		ans= solve(0,0,1);
		
		s= to_string(L-1);
		
		memset(dp,-1,sizeof dp);
		ans= ans - solve(0,0,1);
		
		cout<<ans<<endl;
	}
	
	return 0;
}



