/*
*
*Problem Link : https://practice.geeksforgeeks.org/problems/occurences-of-2-as-a-digit/1
*Platform: GeeksforGeeks
*Status: Correct
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

long long int dp[10][2][10]; //for position, tight and number of 2's
string s;
long long int solve(int pos,int tight, long long sum){
    if(pos >= s.length())
        return sum;
    if(dp[pos][tight][sum] != -1)
        return dp[pos][tight][sum];
    
    long long int ans = 0;
    int end = ((tight)?(s[pos]-'0'):9);
    for(int i=0 ; i<=end ; i++){
        if(i==2)
            ans+= solve(pos+1 , tight&(i == end) , sum+1);
        else
            ans+= solve(pos+1 , tight&(i == end) , sum);
    }
    
    return dp[pos][tight][sum] = ans;
}

/* Counts the number of '2' digits between 0 and n */
long long int numberOf2sinRange(long long int number)
{
// Your code goes here
    s = to_string(number);
    memset(dp , -1 , sizeof dp);
    return solve(0,1,0);
}

int main(){
	lld T;
	cin >> T;
	
	while(T--){
		lld n;
		cin >> n;
		cout << numberOf2sinRange(n) << endl;
	}
	return 0;
}


