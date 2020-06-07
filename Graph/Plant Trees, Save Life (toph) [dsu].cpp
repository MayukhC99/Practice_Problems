/*
*
*Problem Link : https://toph.co/p/plant-tree-save-life
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

lld x[100009];
lld minimum[100009];

class dsu{
	public:
		vector<lld> parent,rank;
		lld total_components;
		
		dsu(lld n){
			parent.resize(n);
			rank.resize(n);
			for(lld i=0 ; i<n ; i++)
				parent[i] = i, rank[i] = 0;
				
			total_components = n;
		}
		
		lld find(lld a){
			if(a==parent[a])
				return a;
			return parent[a] = find(parent[a]);
		}
		
		void union_set(lld a,lld b){
			a = find(a); //finding root node of a
			b = find(b); //finding root node of b
			
			if( a != b ){
				if(rank[a]<rank[b])
					swap(a,b);
				else if(rank[a] == rank[b])
					rank[a]++;
					
				parent[b] = a;
				total_components--;
			}
			
			return ;
		}
};



int main(){
	speed;boost;
	memset(minimum,-1,sizeof minimum);
	
	lld n,k;
	cin>>n>>k;
	F(x,n);
	dsu d(n);
	
	for(lld i=0 ; i<k ; i++){
		lld a,b;
		cin>>a>>b;
		d.union_set(a-1,b-1);
	}
	
	for(lld i=0 ; i<n ; i++){
		lld xi = x[i];
		lld parent = d.find(i);
		if( minimum[parent] < 0 )
			minimum[parent] = xi;
		else
			minimum[parent] = min( minimum[parent] , xi );
	}
	
	lld ice_cream = 0;
	for(lld i=0 ; i<n ; i++){
		if(d.parent[i]==i)
			ice_cream+= minimum[i];
	}
	
	cout<<ice_cream;
	
	return 0;
}



