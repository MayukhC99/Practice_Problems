#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;

int maxor(int* ary, int ch, int k, int lim){
    if(k == 0){
        return ch;
    }
    if(lim == 0) return 0;
    int x= maxor(ary+1, ch, k, lim-1);
    int y= maxor(ary+1, ch^(*ary), k-1, lim-1);
    
    return max(x,y);
    
}

int main(){
	
	speed;
	boost;
	
	int T;
	cin>>T;
	
	while(T--){
		int n,k;
		
		cin>>n>>k;
		
		int ar[n];
		F(ar,n);
		
		int max= maxor(ar,0,k,n);
		
		cout<<max<<endl;
		
	}
	
	return 0;
}

