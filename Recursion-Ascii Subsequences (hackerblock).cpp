#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

vector<string> result;
int count=0;

void recurse(string ans,string s,int i){

	if(i==s.length()){
		::count++;
		result.push_back(ans);
		
		return ;
	}

	recurse(ans,s,i+1);
	recurse(ans + s[i], s, i+1);
	recurse(ans+ to_string((int)(s[i])), s, i+1);

}

int main(){

	string s;
	cin>>s;

	recurse("",s,0);
	for(int i=0;i<result.size();i++)
		cout<<result[i]<<" ";
	cout<<endl<<::count;

	return 0;
}


