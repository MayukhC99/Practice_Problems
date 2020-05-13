#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

using namespace std;

int main(){
	speed;
	boost;
	
	lld n;
	cin>>n;
	lld ar[n];
	
	for(lld i=0;i<n;i++)
		cin>>ar[i];
	
	
	sort(ar,ar+n);
	lld total=0;
	for(lld i=0;i<n;i++){
		lld temp= (i+1)-ar[i];
		
		total+= abs(temp);
	}
	
	cout<<total;
	
	return 0;
}
