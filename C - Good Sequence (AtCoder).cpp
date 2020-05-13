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
	
	unordered_map<lld,lld> mp;
	
	for(lld i=0;i<N;i++){
		lld c;
		cin>>c;
		mp[c]++;
	}
	
	lld sum=0;
	for(auto it= mp.begin();it != mp.end(); it++){
		if(it->second < it->first)
			sum+= (it->second);
		else if(it->second > it->first)
			sum+= (it->second - it->first);
		
	}
	
	cout<<sum;
	
	return 0;
}

