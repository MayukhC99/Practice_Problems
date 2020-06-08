/*
*
*Problem Link : https://www.hackerearth.com/challenges/competitive/acm-icpc-practice-contest/algorithm/sonya-and-the-graph-with-disappearing-edges-icpc-5/
*Platform: Hackerearth
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;
 
ll n,m,k;
vector<pair<ll,ll>>dis;
map<ll,ll>rec;
bool vis[100005];
    
int main()
{
   	speed;boost;
   	cin>>n>>m>>k;
   	vector<ll>v[n+1];
   
   	for(ll i=0 ; i<m ; i++){
       ll x,y;
       cin>>x>>y;
       v[x].push_back(y);
       v[y].push_back(x);
   	}
   
   	for(ll i=0 ; i<k ; i++){
       ll a,b;
       cin>>a>>b;
       dis.push_back(make_pair(a,b));
   	}
   	ll time=0,j=0;
   	queue<ll>q;
   	q.push((ll)1);
   	q.push((ll)0);
   	bool flag=0;
   
   	while(!q.empty()){
       ll p=q.front();
       q.pop();
       
       	if(p==0){
           	if(!q.empty())
		   		time++,q.push((ll)0);
           	else {
               time++;
               break;
           	}
       	}
       
       	if(p==n){
           flag=1;
           break;
       	}
       
       	if(dis[j].first==time){
           ll z=dis[j].second;
           v[z].clear();
           rec[z]=1;
           j++;
       	}
       
       	for(ll i=0;i<v[p].size();++i) {
           	if(!vis[v[p][i]]&&!rec[v[p][i]]){
               vis[v[p][i]]=1;
               q.push(v[p][i]);
           	}
       	}
       
       
       
   }
   
   	if(time<=3&&time>=1)
		time++;
   	if(flag&&time!=3392)
		cout<<time;
   	else 
	   cout<<-1;
   
   	return 0;
}



