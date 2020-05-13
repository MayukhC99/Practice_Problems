#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

lld count;
vector<lld> result;
stack<vector<lld>> st;

void printv(vector<lld> ar){
	for(lld i=0;i<ar.size();i++)
		cout<<ar[i]<<" ";
	cout<<" ";
	return;
}

void recurse(vector<lld> result,vector<lld> ar,lld target,lld sum,lld i){

	if(i==ar.size()){

		if(sum==target){
			::count++;
			st.push(result);
		}

		return;
	}
	
	recurse(result,ar,target,sum,i+1);

	result.push_back(ar[i]);
	sum+= ar[i];

	recurse(result,ar,target,sum,i+1);

}

int main() {
	::count=0;
	lld N,target;
	cin>>N;
	vector<lld> ar(N);
	vector<lld> result;

	for(lld i=0;i<N;i++)
		cin>>ar[i];
	cin>>target;

	recurse(result,ar,target,0,0);
	while(! ::st.empty()){
		printv(st.top());
		st.pop();
	}
	cout<<endl<<::count;

	return 0;
}
