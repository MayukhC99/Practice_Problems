/*
*
*Problem Link : https://codeforces.com/contest/45/problem/D
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


const int k=1e7+7;
# define pi pair<pair<int,int>,int>

bool vis[k];

int main(){
	
	int n;
	cin>>n;
	memset(vis,0,sizeof(vis));
	vector<pair<pair<int,int>,int>>v;
	
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		v.push_back(make_pair(make_pair(r,l),i));
	}
	
	sort(v.begin(),v.end());
	int ans[n];
	
	for(int i=0;i<n;i++){
		 int a=v[i].first.second;
		 while(vis[a])++a;
		 vis[a]=true;
		 ans[v[i].second]=a;
	 }
	 
	 for(int i=0;i<n;i++)
		 cout<<ans[i]<<" ";
		 
	return 0;
 }


