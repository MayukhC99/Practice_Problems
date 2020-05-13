#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int main(){
	
	lld n;
	cin>>n;
	lld A[n+1],B[n+1];
	
	F(A,n);
	F(B,n);
	
	lld sum_a = 0 ;
	lld sum_b = 0 ;
	
	sort(A,A+n,greater<lld>());
	sort(B,B+n,greater<lld>());
	
	//bool flaga= true;
	
	lld ja= 0;
	lld jb= 0;
	
	for(lld i=0;i<n;i++){
		
			
		if( (ja>=n) || ((jb<n) && A[ja]<B[jb]) )
			jb++;
		else {
			sum_a+= A[ja];
			ja++;
		}
			
	
		if( (jb>=n) || ((ja<n) && B[jb]<A[ja]) )
			ja++;
		else {
			sum_b+= B[jb];
			jb++;
		}
			
		
		//flaga= !flaga;
	}
	
	cout<<(sum_a-sum_b);
	
	return 0;
}


