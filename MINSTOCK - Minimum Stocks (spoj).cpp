#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;


int main(){
	
	speed;
	boost;
	
	lld N;
	cin>>N;
	
	priority_queue<pair<lld,string>,vector<pair<lld,string>>,greater<pair<lld,string>>> q;
	map<string,lld> mp;
	lld count=0;
	
	while(N--){
		int test;
		string s;
		lld cost;
		
		count++;
		
		cin>>test;
		cin>>s;
		
		if(test==3){
			//He is going to buy
			while(!q.empty()){
				
				pair<lld,string> p= q.top();
				q.pop();
				
				if(mp[p.second]==p.first){
					cout<<p.second<<" "<<count<<endl;
					mp.erase(p.second);
					break;
				}
			}
			
			
			continue;
		}
		
		cin>>cost;
		
		q.push({cost,s});
		mp[s]=cost;
	}	
	
	return 0;
}

