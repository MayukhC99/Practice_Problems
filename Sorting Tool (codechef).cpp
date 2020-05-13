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

struct compare {
    bool operator() (const pair<lld,lld>& lhs, const pair<lld,lld>& rhs) const {
        return lhs>rhs;
    }
};

int main(){
	
	lld N,M;
	cin>>N>>M;
	
	lld pos[M+1]={0};
	
	lld ar[N];
	F(ar,N);
	
	map<lld,lld> mp;
	
	for(lld i=0;i<N;i++){
		
		if(mp[ar[i]] == 0)
			pos[ar[i]]= i;
			
		mp[ar[i]]++;	
	}
	
	
	set<pair<lld,lld>,compare> st;
	for(auto it= mp.begin(); it != mp.end(); it++)
		st.insert({it->second,it->first});
		
//	for(auto it= st.begin(); it!= st.end(); it++)
//		cout<<(*it).first<<" "<<(*it).second<<endl;
	
	for(auto it= st.begin(); it != st.end(); it++){
		lld num= (*it).first;
		set<pair<lld,lld>> temp;
		
		if(it== prev(st.end())){
			
			lld n= mp[((*it).second)];
			for(lld i=1;i<=n;i++){
				cout<<(*it).second<<" ";
			}
		}
		else{
			auto jt= it;
			for( ; jt != prev(st.end()); jt++){
				if((*jt).first != (*next(jt)).first)
					break;
				else
					temp.insert({pos[(*jt).second],(*jt).second});
			}
			temp.insert({pos[(*jt).second],(*jt).second});
			it= jt;
			
			for(auto k= temp.begin(); k != temp.end(); k++){
			//cout<<(*k).second<<" ";
			lld n= mp[((*k).second)];
			for(lld i=1;i<=n;i++)
				cout<<(*k).second<<" ";
			}
		
		
		}
	}
	
	return 0;
}
