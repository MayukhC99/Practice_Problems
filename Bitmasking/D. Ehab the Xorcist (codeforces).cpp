/*
*
*Problem Link : https://codeforces.com/problemset/problem/1325/D
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


int main(){
	
	speed; boost;
    long long u,v;
    
    cin>>u>>v;
    if (u % 2 != v % 2 || u>v){
        cout<<"-1";
        return 0;
    }
    
    
    if (u==v){
        if (!u)
        	cout<<"0";
        else
        	cout<<"1"<<endl<<u;
        return 0;
	}
        
    long long x=(v-u)/2;
  
    if ( u & x )
    	cout<<"3"<<endl<<u<<" "<<x<<" "<<x;
    else
    	cout<<"2"<<endl<<(u^x)<<" "<<x;
    	
    return 0;
}


