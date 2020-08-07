/*
*
*Problem Link : https://codeforces.com/problemset/problem/1251/A
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


int main(){
	speed;
	
	lld t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		set<char> ans;
		
		for(lld i=0 ; i<s.length() ; i++){
			lld cnt = 0; lld j = i ;
			for( ; j<s.length()-1 ; j++){
				if(s[j] == s[j+1])
					cnt++;
				else
					break;
			}
			if( cnt%2 == 0 )
				ans.insert(s[j]);
			i = j;
		}
		
		if( s.length() > 1 ){
			if(s[s.length()-1] != s[s.length()-2])
				ans.insert(s[s.length()-1]);
		}
		else
			ans.insert(s[0]);

		for(auto it = ans.begin() ; it != ans.end() ; it++)
			cout << (*it);
		cout << endl;
	}
	return 0;
}


