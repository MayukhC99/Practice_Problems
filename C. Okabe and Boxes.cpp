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
	
	lld N;
	cin>>N;
	
	N=N*2;
	
	
	stack<lld> st;
	lld count=0;
	lld ans=0;
	while(N--){
		string s;
		lld a;
		cin>>s;
		
		if(s=="add"){
			cin>>a;
			st.push(a);
		}
		else {
			count++;
			
			if(!st.empty()){
				if(st.top()==count)
					st.pop();
				else {
					st= stack<lld>();
					ans++;
				}
			}
			else
				continue;
		}
		
	}
	
	cout<<ans;
	
	return 0;
}
