/*
*
*Problem Link : https://app.codesignal.com/interview-practice/task/cHYqbQ9DiWmejAdeG
*Platform: codesignal
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


std::vector<std::string> composeRanges(std::vector<int> nums) {
    vector<string> ans;
    if(nums.empty())
        return ans;
    int dp = nums[0];
    int i = 1;
    for( ; i<nums.size() ; i++){
        if(nums[i]-nums[i-1] == 1)
            continue;
        else {
            string s= "";
            if(dp-nums[i-1] == 0)
                s+= to_string(dp);
            else
                s+= to_string(dp)+"->"+to_string(nums[i-1]);
            ans.push_back(s);
            dp = nums[i];
        }
    }
    
    string s= "";
    if(dp-nums[i-1] == 0)
        s+= to_string(dp);
    else
        s+= to_string(dp)+"->"+to_string(nums[i-1]);
    ans.push_back(s);
    
    return ans;
}


