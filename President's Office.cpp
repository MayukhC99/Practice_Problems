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
	
	int row,col;
	char R;
	cin>>row>>col>>R;
	
	char ar[row+1][col+1];
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>ar[i][j];
			
	
	int count=0;
	unordered_map<char,int> mp;
	
	for(int i=0;i<row;i++){
		for(int j=0;j<col;j++){
			if(ar[i][j]==R){
				if((i-1 >= 0) && (ar[i-1][j] != '.') && (ar[i-1][j] != R)){
					if(mp[ar[i-1][j]]==0){
						count++;
						mp[ar[i-1][j]]= 1;
					}
				}
				if((i+1 < row) && (ar[i+1][j] != '.') && (ar[i+1][j] != R)){
					if(mp[ar[i+1][j]]==0){
						count++;
						mp[ar[i+1][j]]= 1;
					}
				}
				if((j-1 >= 0) && (ar[i][j-1] != '.') && (ar[i][j-1] != R)){
					if(mp[ar[i][j-1]]==0){
						count++;
						mp[ar[i][j-1]]= 1;
					}
				}
				if((j+1 < col) && (ar[i][j+1] != '.') && (ar[i][j+1] != R)){
					if(mp[ar[i][j+1]]==0){
						count++;
						mp[ar[i][j+1]]= 1;
					}
				}
			}
		}
	}
	
	cout<<count;
	
	return 0;
}
