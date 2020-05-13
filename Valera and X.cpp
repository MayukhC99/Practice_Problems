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
	
	speed;
	boost;
	
	int n;
	cin>>n;
	
	char ar[n+1][n+1];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>ar[i][j];
	
	char x= ar[0][0];
	char o= ar[0][1];
	
	if(x==o){
		cout<<"NO";
		return 0;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				if(ar[i][j] != x){
					cout<<"NO"; return 0;
				}
			}
			else if((i+j)==(n-1)){
				if(ar[i][j] != x){
					cout<<"NO"; return 0;
				}
			}
			else {
				if(ar[i][j] != o){
					cout<<"NO"; return 0;
				}
			}
		}
	}
	
	
	cout<<"YES";
	
	return 0;
}
