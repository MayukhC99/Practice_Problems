#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

using namespace std;

#define ll long long int
#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<=n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}}cout<<endl;
#define AS 200001

char phone[][10]={ " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };
string searchIn [] = {"prateek", "sneha", "deepak", "arnav", "shikha", "palak","utkarsh", "divyam", "vidhi", "sparsh", "akku"};

void PhoneKeyPad(char* in,char* out,int i,int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		 //cout<<"out is "<<out<<endl;
		 
		for(int k=0;k<11;k++){
			if(searchIn[k].find(out) != string::npos){
				cout<<searchIn[k]<<endl;
			}
		}

		return;
	}

	int indx = in[i] - '0';
	for(int k = 0; phone[indx][k]!='\0';k++){
		out[j] = phone[indx][k];
		PhoneKeyPad(in,out,i+1,j+1);
	}
}

int main(){
	
	speed;
	boost;
	
	char in[100],out[100];
	cin>>in;
	PhoneKeyPad(in,out,0,0);

	return 0;
}
