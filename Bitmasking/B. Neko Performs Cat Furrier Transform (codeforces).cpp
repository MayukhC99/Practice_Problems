/*
*
*Problem Link : https://codeforces.com/problemset/problem/1152/B
*Platform: codeforces
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


vector<int> ops;

bool ok(int x) {
  return !((x+1) & x);
}

void opB(int& x) {
  ++x;
}

void opA(int& x) {
  int p;
  for (int i=0; (1<<i)<=x; ++i)
    if (!((x>>i) & 1)) {
      p = i;
    }
  ops.push_back(p + 1);
  x ^= (1<<(p+1)) - 1;
}

int main() {
	speed;boost;
	
  int x, step=0;
  cin >> x;
  while (!ok(x)) {
    ++step;
    opA(x); 
    if (ok(x)) break;
    ++step;
    opB(x);
  }

  cout << step << endl;
  P(ops,ops.size());
  cout << endl;
  
  
  return 0;
}


