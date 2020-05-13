#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;
lld mint= INT_MAX;

void recurse(lld i,lld j,lld count){
	if(i==1 && j==1){
		if(mint<count)
			mint=count;
		return;
	}
	if(j-i>0)
	recurse(j-i,j,count+1);
	if(i-j>0)
	recurse(i,i-j,count+1);
}

int main(){
	
	lld n;
	cin>>n;
	
	
	for(lld i=1;i<n;i++){
		recurse(i,n-i,1);
	}
	
	cout<<mint;
	
	return 0;
}
