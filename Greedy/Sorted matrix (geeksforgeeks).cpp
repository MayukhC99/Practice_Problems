/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/sorted-matrix/0
*Platform: geeksforgeeks
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL);
#define booster cout.tie(NULL)
#define endl "\n"

typedef long long int lld;

#define mp make_pair
#define pb push_back
#define fi first
#define si second
#define pii pair<lld,lld>
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

#define mod 1000000007
const lld inf= 1e12;

using namespace std;


int main() {
	//code
	int T;
	cin >> T;
	while(T--){
	    int N;
	    cin >> N;
	    int mat[N+1][N+1];
	    for(int i=0; i<N; i++)
	        for(int j=0; j<N; j++)
	            cin >> mat[i][j];
	    
	    int max_ele = mat[N-1][N-1];
	    //applying counting sort;
	    vector<int> count(max_ele+1 , 0);
	    
	    for(int i=0; i<N; i++)
	        for(int j=0; j<N ; j++)
	            count[ mat[i][j] ]++;
	   
	    //printing
	    for(int i=0; i<=max_ele ; i++)
	        while(count[i]--)
	            cout << i << " ";
	    cout << endl;
	}
	
	return 0;
}


