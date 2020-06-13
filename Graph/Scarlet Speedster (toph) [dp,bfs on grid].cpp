/*
*
*Problem Link : https://toph.co/p/scarlet-speedster
*Platform: toph
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

lld dp[105][105];

lld N,M,X,Y;

int dr[]={ 1 , -1 , 0 , 0 }; //direction vector for row
int dc[]={ 0 , 0 , 1 , -1 }; //direction vector for column

void bfs( vector<vector<lld>>& adj , vector<vector<bool>>& vis , bool flag ){
	
	priority_queue< pair<lld,pii> , vector<pair<lld,pii>> , greater<pair<lld,pii>> > q;
	q.push( { 0, { 0 , 0 } } );
	dp[0][0] = 0 ;
	
	while(!q.empty()){
		
		lld r = q.top().si.fi;
		lld c = q.top().si.si;
		q.pop();
		
		if(vis[r][c])
			continue;
		
		vis[r][c] = true;
		
		for(int i=0; i<4 ; i++){
			
			lld rr = r + dr[i];
			lld cc = c + dc[i];
			
			if(rr<0 || cc<0 || rr>=N || cc>=M)
				continue;
			
			
			if( flag ){
					
				lld time = (abs(adj[r][c]-adj[rr][cc])%2==0)?0:X;
					
				if(dp[r][c]+time < dp[rr][cc]){
					dp[rr][cc] = dp[r][c] + time;
					q.push( { dp[rr][cc] , {rr,cc} } );
				}
					
					
					
			} 
			else {
					
				lld time = (abs(adj[r][c]-adj[rr][cc])%2==0)?Y:0;
					
				if(dp[r][c]+time < dp[rr][cc]){
					dp[rr][cc] = dp[r][c] + time;
					q.push( { dp[rr][cc] , {rr,cc} } );
				}
					
					
					
			}
		
		}
		
	}
	
	
}


int main(){
	speed;
	lld T;
	cin>>T;
	
	while(T--){
		cin>>N>>M>>X>>Y;
		vector<vector<lld>> adj(N+1 , vector<lld>(M+1));
		NF(adj,N,M);
		vector<vector<bool>> vis(105 , vector<bool>(105,false));
		
		for(lld i=0;i<105;i++)
			for(lld j=0; j<105; j++)
				dp[i][j] = inf;
		
		bfs(adj,vis,true);
		lld flash = dp[N-1][M-1];
		
		for(lld i=0;i<105;i++)
			for(lld j=0; j<105; j++){
				dp[i][j] = inf;
				vis[i][j] = false;
			}
		
		bfs(adj,vis,false);
		lld rflash = dp[N-1][M-1];
		
		
		if(flash < rflash)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}


