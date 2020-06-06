/*
*
*Problem Link : https://codeforces.com/problemset/problem/999/E
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

template<class T>
class graph{
	unordered_map<T,vector<T>> adj;
	
	public:
		vector<bool> visited;
		
		graph():visited(10000,false){}
		
		void add_edge(T x , T y , bool un_directed=false){
			adj[x].push_back(y);
			if(un_directed)
				adj[y].push_back(x);
		}
		
		void dfs(T start){
			visited[start]= true;
			for(T connected : adj[start])
				if(!visited[connected])
					dfs(connected);
		}
		
		T dfs_modified(T start){
			vector<bool> vis= visited;
			lld count=0;
			stack<T> st;
			st.push(start);
			
			while(!st.empty()){
				T v= st.top();
				vis[v]= true;
				count++;
				st.pop();
				
				for(T connected : adj[v]){
					if(!vis[connected]){
						
						st.push(connected);
					}
				}
			}
			
			return count;
		}
		
		
};

int main(){
	
	lld n,m,capital; //n= no. of citites and m= no. of roads and capital= capital city
	cin>>n>>m>>capital;
	
	graph<lld> g;
	
	for(lld i=0 ; i<m ; i++){
		lld x,y;
		cin>>x>>y;
		g.add_edge(x,y);
	}
	
	g.dfs(capital);//running dfs from capital city to get all visited marked
	
	//finding out all non_visitable vertices from the capital city
	vector<lld> not_visited;
	for(lld i=1 ; i<=n ; i++)
		if(!g.visited[i])
			not_visited.push_back(i);
	
	priority_queue< pair<lld,lld> > q;
	for(lld ele : not_visited)
		q.push( { g.dfs_modified(ele) , ele } );
	

	
	lld ans = 0;
	while(!q.empty()){
		pair<lld,lld> pr = q.top();
		q.pop();
		
		if(!g.visited[pr.second]){
			g.dfs(pr.second);
			ans++;
		}
	}
	
	cout<<ans;
	
	return 0;
}


