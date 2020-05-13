#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

bool recurse(string s,int i){

	if(i>=s.length())
		return true;

	if(s[i]!='a' && s[i]!='b')
		return false;
	if(s[i]=='b'){
		if((i< s.length()-1) && s[i+1]=='b')
			return recurse(s,i+2);
		else 
			return false;
	}

	return recurse(s,i+1);
}

int main(){
	string s;
	cin>>s;

	if(recurse(s,0))
		cout<<"true";
	else
		cout<<"false";

	return 0;
}


