#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;
set<string> result;

void recurse(string ans,string s){

	if(s.length()==0){
		result.insert(ans);
		return;
	}

	for(int i=1;i<=2;i++){
		if(s.length()<i)
			return;
			
		int c= stoi(s.substr(0,i));
		if(c>26)
			return;
			
		recurse(ans+ (char)((c-1)+'a'), s.substr(i));
	}
}


int main() {
	string s;
	cin>>s;
	recurse("",s);

	cout<<"[";
	auto it= result.begin();
	for( ; it != prev(result.end(),1); it++)
		cout<<(*it)<<", ";
	cout<<(*it)<<"]";
	
	return 0;
}

