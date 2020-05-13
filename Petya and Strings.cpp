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
	
	string s1;
	string s2;
	
	cin>>s1>>s2;
	
	int n1= s1.length();
	int n2= s2.length();
	
	int k=0;
	for(int i=0;i<n1;i++){
		
		if(k>=n2){
			cout<<"1";
			return 0;
		}
		
		int r1= ((int)(s1[i]-'a'))<0 ? (int)(s1[i]-'A') : (int)(s1[i]-'a');
		int r2= ((int)(s2[k]-'a'))<0 ? (int)(s2[k]-'A') : (int)(s2[k]-'a');
		k++;
			
		if(r1!=r2){
			if((r1-r2)>0)
				cout<<"1";
			else
				cout<<"-1";
			return 0;
		}
		
	}
	
	if(n2>n1)
		cout<<-1;
	else
		cout<<"0";
	
	return 0;
}
