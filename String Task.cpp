#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	string s;
	cin>>s;
	
	transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return tolower(c); });
	
	string result="";
	
	int n= s.length();
	for(int i=0;i<n;i++){
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
			continue;
		else
			result+='.';
			result+=s[i];
	}
	
	cout<<result;
	
	return 0;
}
