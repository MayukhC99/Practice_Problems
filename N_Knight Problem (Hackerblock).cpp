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

int cnt=0;

bool check(int ar[100][100],int i,int j){
	//cout<<"start and i "<<i<<" and j "<<j<<" ar is "<<ar[i][j]<<endl;
	if(ar[i][j]==1)
		return false;
	if(ar[i+1][j+2]==1 || ar[i+1][j+1]==1)
		return false;
	if(j-2>=0 && ar[i+1][j-2]==1)
		return false;
	if(j-1>=0 && ar[i+2][j-1]==1)
		return false;
	if(i-1>=0 && ar[i-1][j+2]==1)
		return false;
	if(i-1>=0 && j-2>=0 && ar[i-1][j-2]==1)
		return false;
	if(i-2>=0 && ar[i-2][j+1]==1)
		return false;
	if(i-2>=0 && j-1>=0 && ar[i-2][j-1]==1)
		return false;
	return true;
}

void nknights(int ar[100][100],int n,int col,int row, int no){
	
	if(no==0){
		
		cnt++;

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ar[i][j] == 1)
					cout<<"{"<<i<<"-"<<j<<"}"<<" ";
			}
		}
		cout<<" ";
			
		return ;
	}
	
	for(int i=row;i<n;i++){
		for(int j=col;j<n;j++){
			if(check(ar,i,j)){
			
			
				ar[i][j]= 1;
			
				nknights(ar,n,j,i,no-1);
			
				ar[i][j]=0;
			}
		}
		col= 0;
	}
	
	return ;
	
}

int main(){
	
	int n;
	cin>>n;
	
	int ar[100][100]={0};
	
	nknights(ar,n,0,0,n);
	
	cout<<endl<<cnt;
	
}
