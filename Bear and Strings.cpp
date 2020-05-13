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
lld sum=0;

void CalculateTable(string p){
	int i=1;
	int j=0;
	int lp = p.length();
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

	int i=0,j=0;
	int prev=-1;
	int ls = s.length();
	int lp = p.length();

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
			int dif= i-j;
			int right= ls-(dif+3);
			//cout<<"right "<<right<<endl;
			int left= (dif-(prev+1))*right;
			//cout<<"left "<<left<<endl;
			sum+= (left+right);
			//cout<<"Pattern Found at Index : "<<i-j<<" and sum is "<<sum<<endl;
			j = table[j-1];
			prev= dif;
		}
	}

}


int main(){
	
	string s;
	cin>>s;
	
	string sub="bear";
	
	KMP(s,sub);
	
	cout<<sum;
	
	return 0;
}
