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

void floodfill(int ar[][6],int row,int i,int j,int& maxt,int sum){
	if(i<0 || i>=5 || j<0)
		return;
	if(j==0){
		sum= sum+ ar[j][i];
		maxt= max(sum,maxt);
		//cout<<"Final i "<<i<<" j "<<j<<" sum = "<<sum<<endl;
		return;
	}
	
	sum= sum+ ar[j][i];
	//cout<<"i "<<i<<" j "<<j<<" sum = "<<sum<<endl;
	
	floodfill(ar,row,i-1,j-1,maxt,sum);
	floodfill(ar,row,i,j-1,maxt,sum);
	floodfill(ar,row,i+1,j-1,maxt,sum);
}

int main(){
	
	speed;
	boost;
	
	int col= 5;
	int T;
	cin>>T;
	
	while(T--){
		int row;
		
		cin>>row;
		
		int ar[row+1][6]={0};
		NF(ar,row,col);
		
		int r= min(row,5);
		
		
//		for(int i= r-1;i>=r-5; i--){
//			for(int j= 0;j<5;j++){
//				if(ar[i][j]==-1)
//					ar[i][j]=0;
//			}
//		}
		
		for(int i=0;i<r;i++){
			for(int j=0;j<5;j++){
				if(ar[i][j]==-1)
					ar[i][j]=0;
			}
		}
				
		
		int max=INT_MIN;
		
		floodfill(ar,row,2,row,max,0);
		
		cout<<max<<endl;
		
	}
	
	
	
	return 0;
}
