#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

set<string> result;

void permute(string a, int l)  
{   
    if (l == a.length()-1)
        result.insert(a);  	
    else
    {   
        for (int i = l; i < a.length(); i++)  
        {  
   
            swap(a[l], a[i]);  
   
            permute(a, l+1);  
    
            swap(a[l], a[i]);  
        }  
    }  
}

int main(){
	
	string s;
	cin>>s;
	
	permute(s,0);
	
	//sort(result.begin(),result.end());
	
	for(auto it= result.begin();it != result.end() ;it++)
		cout<<(*it)<<" ";
	
	return 0;
}
