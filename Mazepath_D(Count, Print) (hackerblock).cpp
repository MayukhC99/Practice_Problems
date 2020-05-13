#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

set<string,greater<string>> result;
int count=0;

void recurse(int row,int col,int i,int j,string ans){
	if(i<0 || j<0)
		return ;
	if(i>=row || j>=col)
		return ;
	if((i==row-1) && (j==col-1)){
		::count++;
		result.insert(ans);
		return ;
	}

	recurse(row,col,i,j+1, ans + "H");
	recurse(row,col,i+1,j, ans + "V");
	recurse(row,col,i+1,j+1, ans + "D");
}

int main() {
	int row,col;
	cin>>row>>col;

	recurse(row,col,0,0,"");

	for(auto it= result.begin(); it != result.end(); it++)
		cout<<(*it)<<" ";
		
	cout<<endl<<::count;

	return 0;
}


