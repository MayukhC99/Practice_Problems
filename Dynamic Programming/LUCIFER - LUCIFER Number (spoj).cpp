/*
*
*Problem Link : https://www.spoj.com/problems/LUCIFER/
*Platform: spoj
*Status: correct
*Author: Mayukh Chakrabarti
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int ll;

#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define fill(a,v) memset((a),(v),sizeof (a))
#define REP(p,a,b) for(int p=a;p<b;p++)

using namespace std;

ll gcd(ll a,ll b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return gcd(b,a%b);
    else return a;
}

string to_string(ll num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

set<int> s;
int mark[101];

void foo()
{
    for(int i=2;i*i<=100;i++)
    {
        if(mark[i]==0)
        {
            for(int j=i*2;j<=100;j+=i)
                mark[j]=1;
        }
    }
    for(int i=2;i<=100;i++)
        if(mark[i]==0)
            s.insert(i);
}

ll dp[10][2][2][50][50];
int n;
string y;

ll f(int pos,bool smaller_or_not,bool nozero,int oddsum,int evensum)
{
    if(pos==n)
        return (s.find(evensum-oddsum)!=s.end());

    if(dp[pos][smaller_or_not][nozero][oddsum][evensum]>=0)
        return dp[pos][smaller_or_not][nozero][oddsum][evensum];

    ll res=0;
    bool newnozero;

    REP(i,0,10)
    {
        if(smaller_or_not||(i<=(int)(y[pos]-'0')))
        {
            newnozero=(nozero||i>0);
            if(newnozero)
            {
                if(!((n-pos-1)&1)) res+=f(pos+1,(smaller_or_not||(i<(int)(y[pos]-'0'))),true,oddsum+i,evensum);
                else res+=f(pos+1,(smaller_or_not||(i<(int)(y[pos]-'0'))),true,oddsum,evensum+i);
            }
            else
            {
                res+=f(pos+1,(smaller_or_not||(i<(int)(y[pos]-'0'))),false,oddsum,evensum);
            }
        }
    }
    dp[pos][smaller_or_not][nozero][oddsum][evensum]=res;
    return res;
}

int main() {
  	speed;
  	boost;
   
    int t,a,b;
    ll ans;
    cin>>t;
    foo();
    
    while(t--)
    {
        ans=0;
        cin>>a>>b;
        a--;
        if(b>0)
        {
            y=to_string(b);
            n=y.size();
            memset(dp,-1,sizeof dp);
            ans=f(0,false,false,0,0);
        }
        if(a>0)
        {
            y=to_string(a);
            n=y.size();
            memset(dp,-1,sizeof dp);
            ans-=f(0,false,false,0,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
