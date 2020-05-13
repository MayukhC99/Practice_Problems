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
	
	lld n;
	cin>>n;
	vector<lld> first;
	vector<lld> second;
	lld first_sum=0;
	lld second_sum=0;
	int last=0;
	
	for(lld i=0;i<n;i++){
		lld num;
		cin>>num;
		if(num<0){
			lld dem= abs(num);
			second_sum+= dem;
			second.push_back(dem);
			last= -1;
		}
		else {
			first_sum+= num;
			first.push_back(num);
			last= 1;
		}
	}
	
	if(first_sum>second_sum){
		cout<<"first";
		return 0;
	}
	if(second_sum>first_sum){
		cout<<"second";
		return 0;
	}
	
	//sort(first.begin(),first.end(),greater<string>());
	//sort(second.begin(),second.end(),greater<string>());
	
	lld firstn= first.size();
	lld secondn= second.size();
	lld i=0;
	lld j=0;
	
	while(i<firstn && j<secondn){
		
		if( first[i] > second[j] ){
			//cout<<"first is "<<first[i]<<" "<<second[j]<<endl;
			cout<<"first"; return 0;
		}
		else if( second[j] > first[i] ) {
			//cout<<"second is "<<second[j]<<" "<<first[i]<<endl;
			cout<<"second"; return 0;
		}
		
		i++;j++;
	}
	
	if(i<firstn){
		cout<<"first";
		return 0;
	}
	if(j<secondn){
		cout<<"second";
		return 0;
	}
	
	last==1 ? cout<<"first" : cout<<"second"; 
	
	return 0;
}
