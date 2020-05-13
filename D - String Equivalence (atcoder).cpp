#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

void recurse(string s,int i,char n,int f){
	if(i==f){
		cout<<s<<endl;
		return ;
	}
	
	for(char ch='a';ch<=n;ch++){
		recurse(s+ ch, i+1,n+1 ,f);
	}
	
}

int main(){
	
	int n;
	cin>>n;
	recurse("",1,'a',n);
	
	return 0;
}
