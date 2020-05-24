/*
*
*Problem Link : https://codeforces.com/contest/777/problem/D
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

const int MAX= 500005;

int main(){
	speed;boost;
	int n;
	string strs[MAX];
	
	cin>>n;
	cin.ignore();
	
	for (int i = 1; i <= n; i++) 
		getline(cin, strs[i]);
		
	for (int i = n-1; i >= 1; i--){
		
		int j = 1;
		int len = min(strs[i].length(), strs[i+1].length()); 
		while (j < len && strs[i][j] == strs[i+1][j]) 
			j++;
		if (len == 1 || strs[i][j] > strs[i+1][j]) 
			strs[i] = strs[i].substr(0, j);
	}
	
	for (int i = 1; i <= n; i++) 
		cout<<strs[i]<<endl;
	
	return 0;
}


