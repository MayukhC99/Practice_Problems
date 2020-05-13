#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

stack<char> st;
unordered_map<char,char> open;
unordered_map<char,char> close;

bool recurse(string s,int i){
	if(i==s.length())
		return st.empty();
	
	if(open[s[i]] > 1)
		st.push(s[i]);
	if(close[s[i]] > 1){
		if( s[i] == open[st.top()] )
			st.pop();
		else
			return false;
	}
	return recurse(s,i+1);
}

int main() {
	
	open['(']=')'; open['{']= '}'; open['[']=']';
	close[')']='('; close['}']= '{'; close[']']='[';
	
	string s;
	cin>>s;

	if(recurse(s,0))
		cout<<"true";
	else
		cout<<"false";

	return 0;
}
