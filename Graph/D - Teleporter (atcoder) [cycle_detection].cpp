/*
*
*Problem Link : https://atcoder.jp/contests/abc167/tasks/abc167_d
*Platform: atcoder
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
const lld inf= 1e12;

using namespace std;


int main(){
	speed;
	
	lld N,K;
	cin>>N>>K;
	
	unordered_map<lld,lld> adj;
	
	for(lld i=1 ; i<=N ; i++){
		lld x;
		cin>>x;
		adj[i] = x; 
	}
	
	bool vis[N+1] = {0};
	
	lld i = 1;
	lld total_length = 0;
	while(!vis[i]){
		vis[i] = true;
		total_length++;
		i = adj[i];
	}
	
	lld cycle_vertex = i; //i now contains the cycle starting vartex
	
	memset(vis,0,sizeof vis);
	lld cycle_length = 0;
	while(!vis[i]){
		vis[i] = true;
		cycle_length++;
		i = adj[i];
	}
	
	lld m = 0;//this will store the moded value with K
	if(total_length-cycle_length == 0)
		m = K % cycle_length;
	else {
		lld dif= total_length - cycle_length ;
		if(K <= dif){
			lld v = 1;
			while(K--)
				v = adj[v] ;
				
			cout<<v<<endl;
			return 0;
		}
		else {
			K = K - dif ;
			m = K % cycle_length ;
			
		}
	}
	
	i = cycle_vertex;
	memset(vis,0,sizeof vis);
	while(m--)
		i = adj[i] ;
		
		
	cout<<i<<endl;
	
	return 0;
}


