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
	
	string s;
	cin>>s;
	
	int	total_1=0;
	int left_0=0;
	int n=s.length();
	int first_2=n;
	
	
	bool flag=false;
	for(int i=0;i<n;i++){
		
		if(s[i]=='1'){
			total_1 ++;
			continue;
		}
		
		if(!flag && s[i]=='0'){
			left_0 ++;
			continue;
		}
		
		if(!flag && s[i]=='2'){
			first_2= i;
			flag= true;
		}
	}
	
	string result="";
	for(int i=0;i<left_0;i++)
		result+='0';
	for(int i=0;i<total_1;i++)
		result+='1';
	for(int i=first_2;i<n;i++)
		if(s[i]!='1')
			result+=s[i];
		
	cout<<result;
	
	return 0;
}
