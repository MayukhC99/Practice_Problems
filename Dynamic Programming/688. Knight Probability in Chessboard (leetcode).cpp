/*
*
*Problem Link : https://leetcode.com/problems/knight-probability-in-chessboard/
*Platform: leetcode
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

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

class Solution {
public:

double DP[25][25][101] = {0};
int row[8] = {1,1,-1,-1,2,2,-2,-2};
int col[8] = {2,-2,2,-2,1,-1,1,-1};

double knightProbability(int N, int K, int r, int c) {
    

    if(r<0 || r>=N || c<0 || c>=N)
        return 0;
    
    
    if(K==0)
        return 1.0;
    
    if(N<=2)
        return 0;
    
    if(DP[r][c][K])
        return DP[r][c][K];
        
    double ans = 0;    
    for(int i=0;i<8;i++)
        ans += knightProbability(N,K-1,r+row[i],c+col[i]);
    
    return DP[r][c][K] = ans/8.0;
    
    }
};


