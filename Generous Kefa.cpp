#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	speed;
	boost;
	
	unordered_map<char,int> mp;
	lld bl,fr;
	cin>>bl>>fr;
	string s;
	cin>>s;
	
	for(int i=0;i<bl;i++)
		mp[s[i]]++;
		
	for(auto it=mp.begin();it!=mp.end();it++){
		if(it->second > fr){
			cout<<"NO";
			return 0;
		}
	}
	
	cout<<"YES";
	
	return 0;
}
