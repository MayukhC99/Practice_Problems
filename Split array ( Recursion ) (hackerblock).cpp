#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;
int count=0;


void printv(vector<lld> a,vector<lld> b,map<int,int> mp){

	for(int i=0;i<b.size();i++){
		if(mp[i]>0)
			continue;
		else
			cout<<" "<<b[i];
	}
	cout<<" and";
	for(lld i=0;i<a.size();i++)
		cout<<" "<<a[i];
	cout<<endl;
	// for(lld i=0;i<b.size();i++)
	// 	cout<<" "<<b[i];
	// cout<<" and";
	// for(lld i=0;i<a.size();i++)
	// 	cout<<" "<<a[i];
	// cout<<endl;

	return ;
}

void recurse(vector<lld>& ar,vector<lld> sub1,lld i,lld sum,lld tsum,map<int,int> mp){

	if(i==ar.size()){

		if(sum==(tsum-sum) && sub1.size()!=ar.size()){
			::count++;
			printv(sub1,ar,mp);
		}
		
		return;
	}

	recurse(ar,sub1,i+1,sum,tsum,mp);

	sub1.push_back(ar[i]);
	//sub2.erase( find(sub2.begin(),sub2.end(),ar[i]) );
	sum+= ar[i];
	mp[i]=1;

	recurse(ar,sub1,i+1,sum,tsum,mp);

}

int main() {
	lld N;
	cin>>N;
	if(N<=0){
		cout<<"0";
		return 0;
	}
	vector<lld> ar(N);
	vector<lld> sub1;

	lld sum=0;
	for(lld i=0;i<N;i++){
		cin>>ar[i];
		sum+= ar[i];
	}

	// if(sum%2 != 0){
	// 	cout<<"0";
	// 	return 0;
	// }
	map<int,int> mp;
	
	recurse(ar,sub1,0,0,sum,mp);
	cout<<::count;

	return 0;
}
