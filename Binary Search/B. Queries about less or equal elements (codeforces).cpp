/*
*
*Problem Link : https://codeforces.com/problemset/problem/600/B
*Platform: codeforces
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

lld binary(vector<lld>& ar, lld l, lld r, lld x){
	while(l<=r){
		lld mid = l + (r-l)/2;
		if(ar[mid]<=x)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}

int main(){
	speed ;
	lld n , m;
	cin >> n >> m;
	vector<lld> a(n),b(m);
	F(a,n);
	F(b,m);
	sort(a.begin(),a.end());
	
	for(lld i=0; i<m ; i++){
		lld ans = binary(a,0,n-1,b[i]);
		if(ans<0)
			cout << "0 ";
		else
			cout << ans + 1 << " "; 
	}
	
	return 0;
}








