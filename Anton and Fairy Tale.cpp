#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

lld binary(lld n,lld m){
	
	lld l=1;
	lld r=2e9;
	lld val= n-m;
	
	while(l<r){
		lld mid= (l+r)/2;
		lld check= ((mid*(mid+1))/2); //i.e x*(x+1)/2 which is 1+2+3...+x
		
		
		if(check>=val)
			r=mid;
		else
			l=mid+1;
	}
	
	return l+m;
	
}


int main(){
	
	lld n,m;
	cin>>n>>m;
	
	
	if(m>=n){
		cout<<n;
		return 0;
	}
	
	cout<<binary(n,m);
	
	return 0;
}

