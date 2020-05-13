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
	
	lld n,m;
	cin>>n>>m;
	
	lld music[n];
	
	for(lld i=0;i<n;i++){
		lld a,b;
		cin>>a>>b;
		music[i]= (a*b);
	}
	
	lld cum[n];
	cum[0]=music[0];
	for(lld i=1;i<n;i++)
		cum[i]= cum[i-1]+music[i];
	
	for(lld i=0;i<m;i++){
		lld query;
		cin>>query;
		
		auto upper= upper_bound(cum,cum+n,query);
		lld index= (upper-cum);
		
		if(index==0){
			cout<<"1"<<endl;
			continue;
		}
		
		if(cum[index-1]==query)
			cout<<index<<endl;
		else
			cout<<(index+1)<<endl;
	}
	
	return 0;
}


