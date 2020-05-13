#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

using namespace std;

lld binary(lld ar[],lld x,lld l,lld r){

	while(l<=r){
		lld mid= (l+r)/2;
		
		if(ar[mid]<=x)
			l=mid+1;
		else if(ar[mid]>x)
			r=mid-1;
	}
	
	return l;
}

int main(){
	vector<int> result;
	lld n,m;
	cin>>n>>m;
	
	lld a[n],b[m];
	
	for(lld i=0;i<n;i++)
		cin>>a[i];
	for(lld i=0;i<m;i++)
		cin>>b[i];
		
	sort(a,a+n);
	for(lld i=0;i<m;i++){
		int count=binary(a,b[i],0,n-1);
		
		result.push_back(count);	
	}
	
	for(lld i=0;i<result.size();i++)
		cout<<result[i]<<" ";

	return 0;
}
