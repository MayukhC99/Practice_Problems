#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

int N,M;
vector<string> board;
vector<vector<int>> result;
bool flag=false;

void floodfill (int i,int j,vector<vector<int>> ans){
	if(i<0 || j<0)
		return ;
	if(i>=N || j>=M)
		return ;
	if(board[i][j]=='X' || ans[i][j]==1)
		return ;
	if((i==N-1) && (j==M-1)){
		ans[i][j]=1;
		
		result= ans;
		flag=true;
		
		return;
	}
	
	ans[i][j]=1;
	
	floodfill(i-1,j,ans);
	floodfill(i+1,j,ans);
	floodfill(i,j-1,ans);
	floodfill(i,j+1,ans);

}

int main(){
	
	cin>>N>>M;
	vector<vector<int>> ans(N,vector<int>(M,0));
	
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		board.push_back(s);
	}
			
	floodfill(0,0,ans);
	
	if(flag){
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++)
				cout<<result[i][j]<<" ";
			cout<<endl;
		}
	}
	else
		cout<<"NO PATH FOUND";
	
	return 0;
}


