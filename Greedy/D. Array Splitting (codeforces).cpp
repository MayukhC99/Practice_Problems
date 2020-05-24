/*
*
*Problem Link : https://codeforces.com/contest/1175/problem/D
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


const int MAX = 300009;

int main(){
	
	speed;boost;
	
	int n,k;
	int a[MAX];
	
	cin>>n>>k;
	F(a,n);
	
	lld sum = 0;
	vector <lld> v;
	
	for(int i = n - 1; i >= 0; i--){
		
	    sum += a[i];
	    
	    if(i > 0) 
			v.push_back(sum);
	}
	
	lld res = sum;
	
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	
	for(int i = 0; i < k-1; ++i)
	    res += v[i];
	    
	cout<<res<<endl;
	
	
	return 0;
}


