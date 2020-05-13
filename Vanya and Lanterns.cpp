#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	lld n,l;
	cin>>n>>l;
	
	lld ar[n];
	F(ar,n);
	sort(ar,ar+n);
	
	lld max_dif=0;
	
	for(lld i=0;i<n-1;i++){
		
		lld dif= ar[i+1]-ar[i];
		
		if(dif>max_dif)
			max_dif=dif;
		

	}
	
	double red=0;
	red= (double)(max_dif)/2.0;
	
	red= max(red,max((double)ar[0]-0,(double)l-(double)ar[n-1]));
	
	cout<<setprecision(10)<<fixed;
	cout<<red;
	
	return 0;
}

