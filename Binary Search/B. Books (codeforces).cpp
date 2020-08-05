/*
*
*Problem Link : https://codeforces.com/problemset/problem/279/B
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

lld binary(lld& T, lld prev, vector<lld>& ar, lld l, lld r){
	while(l<=r){
		lld mid = l + (r-l)/2;
		if((ar[mid] - prev) <= T)
			l = mid+1;
		else
			r = mid-1;
	}
	return r;
}


int main(){
	speed;
	lld N,T;
	cin >> N >> T;
	vector<lld> ar(N);
	F(ar,N);
	
	for(lld i=1; i<N ; i++)
		ar[i]+= ar[i-1];
		
	lld mx = binary(T,0,ar,0,N-1)+1;
	for(lld i=1; i<N ; i++){
		lld temp = binary(T, ar[i-1], ar, 0, N-1) - i + 1;
		mx = max(temp , mx);
	}
	cout << mx;
	return 0;
}


