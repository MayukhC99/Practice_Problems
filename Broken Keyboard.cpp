#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

using namespace std;

int main(){
	
	speed;
	boost;
	
	int t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		int size= s.size();
		
		bool vis[27];
		for(int i=0;i<26;i++)
			vis[i]=false;
		
		if(size==1)
			vis[(s[0]-'a')]=true;
			
		
		for(int i=0;i<size;){
			
			int count=1;
			for(int j=i;j<size-1 && s[j]==s[j+1];j++)
				count++;
			
			if(count%2!=0)
				vis[(s[i]-'a')]=true;
			i+=count;
			
		}
		
		for(int i=0;i<26;i++){
			if(vis[i]){
				cout<<(char)(i+'a');
			}
		}
		
		cout<<endl;
	}
	
	return 0;
}
