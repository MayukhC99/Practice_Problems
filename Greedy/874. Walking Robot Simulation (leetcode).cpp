/*
*
*Problem Link : https://leetcode.com/problems/walking-robot-simulation/
*Platform: leetcode
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


class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<int> oMap;
        
        for (auto& v : obstacles) 
            oMap.insert(v[0] * 40000 + v[1]);
        
        
        vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direction = 0;
        int x = 0;
        int y = 0;
        int maxDistance = 0;
        
        
        for (int command : commands) {
            
            if (command == -2) {
                
                --direction;
                if (direction == -1)
                    direction = 3;
            } 
            else if (command == -1) {
                
                ++direction;
                if (direction == 4)
                    direction = 0;
            } 
            else {
                
                int testX = x;
                int testY = y;
                
                for (int move = 0; move < command; ++move) {
                    
                    int tempX = testX + offsets[direction][0];
                    int tempY = testY + offsets[direction][1];
                    if (oMap.count(tempX * 40000 + tempY) == 0) {
                        
                        testX = tempX;
                        testY = tempY;
                    } 
                    else 
                        break;
                }
                
                x = testX;
                y = testY;
                maxDistance = max(maxDistance, x * x + y * y);
            }
        }
        
        return maxDistance;
    }
};


