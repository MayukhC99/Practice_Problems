/*
*
*Problem Link : https://codeforces.com/contest/1265/problem/D
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


int main() {
	boost;speed;
    map<int, int> mp;
    
    
    cin >> mp[0] >> mp[1] >> mp[2] >> mp[3];
    int total = mp[0] + mp[1] + mp[2] + mp[3];
    
    for (int st = 0; st < 4; st++) 
		if (mp[st]){
        	vector<int> res;
        	auto tmp = mp;
        	tmp[st]--;
        	res.push_back(st);
        	int last = st;
        	for (int i = 0; i < total - 1; i++) {
        		
            	if (tmp[last - 1]) {
            		
                	tmp[last - 1]--;
                	res.push_back(last - 1);
                	last--;
            	}
            	else if (tmp[last + 1]) {
            		
                	tmp[last + 1]--;
                	res.push_back(last + 1);
                	last++;
            	}
            	else
                	break;
        	}
    		if ((int) res.size() == total) {
    			
        		cout << "YES\n";
        		for (int i = 0; i < (int) res.size(); i++)
            		cout << res[i] << " \n"[i == (int) res.size() - 1];
            
            	return 0;
    		}	
    }
    
    cout << "NO\n";
    
    return 0;
}


