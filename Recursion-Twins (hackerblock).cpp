#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int count=0;

void recurse(string s,int i){
	
	if(i>= s.length()-2)
		return ;
	
	if(s[i]!=s[i+1] && s[i]==s[i+2])
		::count++;
	
	recurse(s,i+1);
}

int main(){
	
	string s;
	cin>>s;
	
	recurse(s,0);
	
	cout<<::count;
	
	return 0;
}
