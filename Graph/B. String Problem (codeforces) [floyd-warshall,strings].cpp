/*
*
*Problem Link : https://codeforces.com/contest/33/problem/B
*Platform: codeforces
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
const lld inf= 1e6;

using namespace std;

int main(){
	speed;
	
	string a;
	string b;
	cin>>a>>b;
	
	lld n;
	cin>>n;
	lld floyd[27][27];

	for(lld k=0; k<26; k++)
		for(lld i=0; i<26; i++)  
			floyd[k][i] = inf; //initializing floyd array with infinity
	
	for(lld i=0; i<n ; i++){
		char x,y; lld w;
		cin>>x>>y>>w;
		floyd[ (int)( x-'a' ) ][ (int)( y-'a' ) ] = min( floyd[ (int)( x-'a' ) ][ (int)( y-'a' ) ] , w );
	}
	
	
	if(a.length()!=b.length()){
		cout<<"-1"<<endl;
		return 0;
	}
	
	for(lld i=0; i<26; i++)
		floyd[i][i] = 0;

	for(lld k=0; k<26; k++)
		for(lld i=0; i<26; i++)
			for(lld j=0; j<26; j++)
				floyd[i][j]= min( floyd[i][j] , (floyd[i][k]!=inf && floyd[k][j]!=inf ) ? (floyd[i][k] + floyd[k][j]):inf );

	
	lld cost = 0;
	string ans="";
	for(lld i=0 ; i<a.length() ; i++){

		if(a[i]==b[i]){
			ans+= a[i];
			continue;
		}
		
		lld mi = inf;
		lld pos = inf;
		for(int j=0 ; j<26 ; j++){
			
			if(floyd[ (int)(a[i]-'a') ][ j ] == inf || floyd[ (int)(b[i]-'a') ][ j ] == inf)
				continue;
			
			lld val = floyd[ (int)(a[i]-'a') ][ j ] + floyd[ (int)(b[i]-'a') ][ j ];
			if(val < mi){
				mi = val;
				pos = j;
			}
		}
		
		if( mi == inf ){
			cout<<"-1"<<endl;
			return 0;
		}
		ans+= (char)(pos+'a');
		cost+= mi;
		
	}
	
	cout<<cost<<endl;
	cout<<ans<<endl;
	
	return 0;
}


