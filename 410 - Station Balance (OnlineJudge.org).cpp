/*
*
*Problem Link : https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=351
*Platform: onlinejudge
*Status: correct
*Author: Mayukh Chakrabarti
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
#define ma 1000

int main(){
	
	//speed;boost;
	
    int C, S, st=1;
    vector<int> ar(ma);
    
    while(scanf("%d %d", &C, &S) != EOF){
    	
    	double imbalance = 0;

        F(ar,S);
            
        double avg = accumulate(ar.begin(),ar.begin()+S,0);
        avg = (double) avg/C;

        for(int i = S ; i< 2*C ; i++)
            ar[i] = 0;
            
        sort(ar.begin(), ar.begin() + 2*C , [&](int a,int b){
        	return a>b;
		});

        cout<<"Set #"<<st<<endl;
        st++;

        for(int i = 0; i< C; i++){
            cout<<" "<<i<<":";

            if(ar[2*C-i-1])
                cout<<" "<<ar[2*C-(i+1)];

            if(ar[i])
                cout<<" "<<ar[i];

            imbalance += fabs(ar[i] + ar[2*C-(i+1)] - avg);
            cout<<endl;
        }
        
        cout<<fixed<<setprecision(5)<<"IMBALANCE = "<<imbalance<<endl<<endl;
        
    }
    
    
    return 0;
}

