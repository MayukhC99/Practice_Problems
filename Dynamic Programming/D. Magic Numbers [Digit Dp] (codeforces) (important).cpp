/*
*
*Problem Link : https://codeforces.com/contest/628/problem/D
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
typedef long long lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;
const lld mod= 1000000007;


/*
* Here we need 5 dp states to identify each number.
* The five states are pos,mo,tight,even,start respectively.
* So we need a 5d array to perform this task
*/
lld dp[2002][2002][2][2][2]; 

lld m,d;
string a,b;
string s;

lld solve(int pos,int mo,bool tight,bool even,bool start){
	
	if(pos == s.length())
		return mo==0 ;
	if(dp[pos][mo][tight][even][start] != -1)
		return dp[pos][mo][tight][even][start];
	
	
	lld ans=0;
	int end= ( (tight)? ( s[pos]-'0' ) : 9 );
	
	if( !start ){
		ans= (ans + solve(pos+1 , mo, tight&(s[pos]=='0'), 0 , 0)) % mod;
		
		for(lld i= 1 ; i<=end ; i++){
			
			if(i != d)
				ans= (ans + solve(pos+1 , (mo*10 + i)%m, tight&(i==end), 1, 1)) % mod;
		}
			
	}
	else {
		for(int i= 0; i<=end ; i++){
		
			if( even and (i == d ) )
				ans= (ans + solve( pos+1 , (mo*10 + i)%m , tight&(i==end) , !even, 1)) % mod;
			else if( (!even) and (i != d ) )
				ans= (ans + solve(pos+1 , (mo*10 + i)%m , tight&(i==end) , !even, 1)) % mod;
		}
	}
	
	return dp[pos][mo][tight][even][start]= ans;
	
}



int main(){
	
	speed;boost;
	
	cin>>m>>d;
	cin>>a>>b;
	
	memset(dp, -1 , sizeof dp);
	s= b;
	lld right= solve(0,0,1,0,0)%mod;
	
	memset(dp, -1 , sizeof dp);
	s= a;
	lld left= solve(0,0,1,0,0)%mod;
	
	lld ans= ((right- left)+mod)%mod;
	
	lld mo=0;
	bool flag=true;
	for(lld i= 1 ; i<= a.length() ; i++){
		if((i%2 == 0) and (a[i-1]-'0' != d)){
			flag= false;
			break;
		}
		else if((i%2 != 0) and (a[i-1]-'0' == d) ){
			flag= false;
			break;
		}
		mo = (mo*10 + (a[i-1]-'0')) % m;
	}
	
	if(mo==0 and flag)
		ans= (ans+1)%mod;
	
	cout<<ans;
	
	return 0;
	
}




