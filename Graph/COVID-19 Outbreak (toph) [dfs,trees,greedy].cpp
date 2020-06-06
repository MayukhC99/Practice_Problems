/*
*
*Problem Link : https://toph.co/p/covid-19-outbreak
*Platform: toph
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

template<class T>
class graph{
	unordered_map<T,vector< pair<T,T> > > adj;
	
	public:
		vector<lld> truck;
		
		void add_edge(T x , pair<T,T> y){
			adj[x].push_back(y);
			adj[y.first].push_back({x , y.second});
		}
		
		T dfs(T start , T previous){

			T sum= truck[start];
			for(pair<T,T> connected : adj[start])
				if(connected.first!=previous)
					sum+= min ( dfs(connected.first , start) , connected.second );
				
			return sum ;
		}
		
		
};

int main(){
	
	speed;boost;
	
	graph<lld> g;
	lld N,Z;
	cin>>N>>Z;
	for(lld i=0 ; i<N-1 ; i++){
		lld u,v,y;
		cin>>u>>v>>y;
		g.add_edge( u , { v , y } );
	}
	
	g.truck.resize(N+1);
	for(lld i=1 ; i<=N ; i++)
		cin>>g.truck[i];
	
	
	cout<<g.dfs(Z,Z);
	
	return 0;
}



