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
	
	lld n,t;
	cin>>n>>t;
	lld ar[n];
	
	for(lld i=0;i<n;i++)
		cin>>ar[i];
		
	lld count=0;
	lld sum=0;
	lld max= 0;
	
	for(lld i=0;i<n;i++){
		sum+=ar[i];
		
		if(sum<=t){
			max++;
		} else {
			sum-=ar[count];
			count++;
		}
	}
	
	cout<<max;
	
	return 0;
}
