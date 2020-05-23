/*
*
*Problem Link : https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/
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
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int na= A.size();
        int nb= B.size();
        
        int one= A[0];
        int two= B[0];
        
        int onel,oner,twol,twor;
        onel= oner= twol= twor= 0;
        
        for(int left=0; left<na ; left++){
            if(A[left]==one && B[left]==one)
                continue;
            (A[left]==one)?oner++ : ((B[left]==one)?onel++ : onel=oner=INT_MAX);
            if(onel==INT_MAX)
                break;
        }
        
        for(int right=0; right<nb ; right++){
            if(A[right]==two && B[right]==two)
                continue;
            (A[right]==two)?twor++ : ((B[right]==two)?twol++ : twol=twor=INT_MAX);
            if(twol==INT_MAX)
                break;
        }
        
        int ans= min(twol,min(twor,min(onel,oner)));
        
        if(ans==INT_MAX)
            return -1;
        else
            return ans;
    }
};



