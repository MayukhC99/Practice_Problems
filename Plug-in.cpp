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
	
	string s;
	cin>>s;
	
	deque<char> q;
	
	lld n= s.length();
	for(lld i=0;i<n;i++){
		
		if(q.empty()){
			q.push_back(s[i]);
			continue;
		}
		
		if(s[i]==q.back()){
			
			q.pop_back();
			
			lld j=i+1;
			for( ;j<n;j+=2){
				if(s[i]==s[j] && s[i]==s[j+1])
					continue;
				else
					break;
			}
			i=j-1;
		}
		else
			q.push_back(s[i]);
		
	}
	
	string result="";
	for(deque<char>::iterator it= q.begin(); it != q.end(); it++)
		result+= (*it);
		
	cout<<result;
	
	return 0;
}
