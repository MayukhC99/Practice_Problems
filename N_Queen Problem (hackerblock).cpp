#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;

using namespace std;

int ans=0;
int N=4;

bool isSafe(vector<vector<int>> board, int row, int col) 
{ 
    int i, j; 
  
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    for (i = row, j = col; j >= 0 && i < N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
  

bool solveNQUtil(vector<vector<int>> board, int col) 
{ 

    if (col >= N) {
    	
    	::ans++;
    	for(int i=0;i<N;i++){
    		for(int j=0;j<N;j++){
    			if(board[j][i]==1)
    				cout<<"{"<<i+1<<"-"<<j+1<<"} ";
			}
		}
		cout<<" ";
    	
    	return true;
	} 

    for (int i = 0; i < N; i++) { 

        if (isSafe(board, i, col)) { 

            board[i][col] = 1; 
  
            solveNQUtil(board, col + 1);
                
            board[i][col] = 0; 
        } 
    } 
  
    return false; 
} 

int main(){
	
	cin>>::N;
	vector<vector<int>> board( N , vector<int> (N, 0));
	
	solveNQUtil(board,0);
	cout<<endl<<ans;

	return 0;
}

