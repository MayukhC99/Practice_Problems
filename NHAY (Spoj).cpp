#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;
int table[10000]={0};

void CalculateTable(string p){
	lld i=1;
	lld j=0;
	lld lp = p.length();
	while(i<lp){

		while(j>0 && p[i]!=p[j]){
			j = table[j-1];
		}

		if(p[i] == p[j]){
			table[i] = j+1;
			i++;
			j++;
		}
		else{
			i++;
		}

	}
}

void KMP(string s,string p){
	CalculateTable(p);

	lld i=0,j=0;
	lld ls = s.length();
	lld lp = p.length();

	while(i<ls){

		while(j>0 && s[i] != p[j]){
			j = table[j-1];
		}

		if(s[i] == p[j]){
			i++;
			j++;
		}
		else{
			i++;
		}
		if(j == lp){
			cout<<i-j<<endl;
			j = table[j-1];
		}
	}

}

int main(){
	speed;
	boost;
	
	lld n;
	while(cin>>n){
		string needle;
		string hay;
	
		cin>>needle;
		cin>>hay;
	
		KMP(hay,needle);
	}
	
	return 0;
}

