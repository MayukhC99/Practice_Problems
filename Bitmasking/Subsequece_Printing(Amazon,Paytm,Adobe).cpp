/*
*
*Problem Link : No Link
*Platform: Mayukh's Computer ;)
*Status: correct
*Author: Mayukh Chakrabarti
*
*Question: print all the subsequences of a given string by bit manipulation
*Asked by: Amazon, Paytm, Adobe
*
*/

#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}
#define P(a,n) for(int i=0;i<n;i++){cout<<a[i]<<' ';}cout<<endl;
#define P1(a,n) for(int i=1;i<=n;i++){cout<<a[i]<<' ';}cout<<endl;
#define NF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cin>>a[i][j];}}
#define NF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cin>>a[i][j];}}
#define PNF(a,n,m) for(int i=0;i<n;i++){for(int j=0;j<m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;
#define PNF1(a,n,m) for(int i=1;i<=n;i++){for(int j=1;j<=m;j++){cout<<a[i][j]<<' ';}cout<<endl;}cout<<endl;

using namespace std;

void solve1(string s){
	
	int len= s.length();
	//now we just need to traverse for (2^len) times
	for(int i=0 ; i < (1<<len) ; i++ ){
		
		/*
		*for every i we need to find position of set bits
		*and print the string characters corresponding
		*to the position
		*/
		int pos=0;
		int digit= i;
		//right shift digit by 1 untill digit becomes 0
		while(digit){
			int n= digit & 1 ;//masking for the 0th position bit in digit
			
			if(n) //if n is 1 then set bit exists at pos position
				cout<<s[pos]; //print the character at pos position
			
			pos++;
			digit= digit >> 1 ;
		}
		
		cout<<endl;
	}
}

//using another way of extraction
int solve2(string s){
	
	int len= s.length();
	//now we just need to traverse for (2^len) times
	for(int i=0 ; i < (1<<len) ; i++ ){
		
		/*
		*for every i we need to find position of set bits
		*and print the string characters corresponding
		*to the position
		*/
		int digit= i;
		/*
		*we need to perform n= digit&(-digit) to extract right most set bit
		*and after operation to eleminate that set bit from actual digit
		*we perform digit= digit-n.
		*we continue this process untill digit is 0
		*/
		while(digit){
			int n= digit & (-digit) ;
			//now n contains the right most set bit of digit
			
			int pos= log2(n); //we get to know the position of set bit by taking log base 2 of its decimal number
			cout<<s[pos]; //print the character at pos position
			
			digit= digit - n ; //eleminating the set bit from position pos of digit
		}
		
		cout<<endl;
	}
}


int main(){
	speed;boost;
	
	string s;
	cin>>s;
	
	solve2(s);
	
	return 0;
}



