#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define booster cout.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int n= s.length();
        
        int left=0;
        int right=0;
        int max=0;
        for(int i=0;i<n;i++){
            
            if(mp.find(s[i])==mp.end()){
                right+=1;
                mp[s[i]]= i;
            }
            else{
                if(mp[s[i]]>=left)
                    left= mp[s[i]]+1;
                mp[s[i]]= i;
                right+=1;
            }
            
            if(right-left > max)
                max= right-left;
            //cout<<"char is "<<s[i]<<" left,right "<<left<<","<<right<<" max is "<<max<<endl;
        }
        
        return max;
    }
};

int main(){
	Solution s;
	
	cout<<s.lengthOfLongestSubstring("tmmzuxt")<<endl;
	
//	unordered_map<char,int> mp;
//	mp['t']++;
//	mp['m']++;
//	
//	for(auto it= mp.begin();it!= mp.end();it++)
//		cout<<it->first<<"   "<<it->second<<endl;
//	
//	mp.erase(mp.begin(),mp.end());
//	
//	for(auto it= mp.begin();it!= mp.end();it++)
//		cout<<itare->first<<"   "<<it->second<<endl;
	
	return 0;
}
