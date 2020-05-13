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

class Solution {
public:
    string simplifyPath(string path) {
        stack<char> st;
        
        int len= path.length();
        for(int i=0;i<len;i++){
            					
            if(!st.empty() && path[i]=='/' && st.top()=='/')
                continue;
            else if(path[i]=='.'){
                if(i+1<len && path[i+1]=='.'){
                    
                    i++;
                    
                    if(st.size()==1)
                        continue;
                    st.pop();
                    
                    while(st.top() != '/' )
                          st.pop();
                }
            }
            else
                st.push(path[i]);
        }
               
        int siz= st.size();
        if(st.top()=='/' && siz != 1){
                st.pop();
                siz--;
        }
                
        
        char ch[siz+1];
        for(int i=siz-1;i>=0;i--){
            ch[i]= st.top();
            st.pop();
        }
      
        ch[siz]='\0';
        
        string result(ch);
        
        return result;
    }
};

int main(){
	
	string s;
	cin>>s;
	
	Solution sol;
	cout<<sol.simplifyPath(s)<<endl;
	
	return 0;
}
