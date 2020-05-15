/*
*
*Problem Link : https://www.spoj.com/problems/CPCRC1C/
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

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;


vector <int> V ;
ll dp[20] , fp[20] ;

void init(ll number)
{
    V.clear();
    while(number!=0)
    {
        V.push_back(number%10);
        number/=10;
    }
}

pair<ll,ll> answer(int pos,bool flag)
{
    if(pos==-1) return make_pair(1,0) ;

    if(flag==0&&dp[pos]!=-1) return make_pair(dp[pos],fp[pos]) ;
    ll ret = 0 , f = 0 ;

    int ending ;
    if(flag) ending = V[pos] ; else ending = 9 ;

    for(int i=0;i<=ending;i++)
    {
        pair<ll,ll> prv = answer(pos-1,flag&&i==ending) ;
        ret = ret+prv.first;
        f = f + i*prv.first + prv.second ;
    }

    if(flag==0) dp[pos] = ret , fp[pos] =f ;

    return make_pair(ret,f) ;
}

ll solve(ll number)
{
    init(number);
    return answer(V.size()-1,1).second ;
}

int main()
{
	speed;boost;
    memset(dp,-1,sizeof dp);
    ll a , b ;
    while(scanf("%lld %lld",&a,&b)==2&&a!=-1&&b!=-1)
        cout<<(solve(b)-solve(a-1))<<endl;
    return 0;
}

