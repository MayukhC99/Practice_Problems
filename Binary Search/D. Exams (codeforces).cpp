/*
*
*Problem Link : https://codeforces.com/problemset/problem/732/D
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


lld N,M;
vector<lld> ar;
vector<lld> preparation;
map<lld,vector<lld>> examDates;

bool canGiveAllExams(lld mid){
	vector<pair<lld,lld>> maximum;
	for(lld i = 1; i<=M ; i++){
		auto it = upper_bound(examDates[i].begin(),examDates[i].end(),mid+1);
		if(it == examDates[i].begin())
			return false;
		maximum.pb( { *(--it) , preparation[i-1] } );
	}
	sort(maximum.begin(),maximum.end());
	lld waste = 0;
	for(lld i = 0 ; i<M ; i++){
		waste+= (maximum[i].second + 1);
		if(maximum[i].first - waste < 0)
			return false;
	}
	return true;
}

lld binary(){
	lld l = 0;
	lld r = N-1;
	while(l<=r){
		lld mid = l + (r-l)/2;
		if(canGiveAllExams(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}
	return l;
}

int main(){
	speed;
	cin >> N >> M ;
	for(lld i=0; i<N; i++){ lld x ; cin >> x ; ar.pb(x) ; }
	for(lld i=0; i<M; i++){ lld x ; cin >> x ; preparation.pb(x) ; }
	for(lld i=0; i<N; i++){
		if(ar[i] == 0)
			continue;
		examDates[ ar[i] ].pb(i+1);
	}
	lld ans = ( binary() + 1 );
	cout << ( ( ans > N ) ? -1 : ans ) ;
	return 0;
}


