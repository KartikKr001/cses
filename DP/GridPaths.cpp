#include<bits/stdc++.h>
#define mod %1000000007
using namespace std;
vector<vector<char>> grid;
vector<vector<int>> dp;
int f(int i,int j,int &n){
    if(i>=n || j>=n || grid[i][j] == '*') return 0;
    if(i==n-1 && j==n-1) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = (f(i+1,j,n)mod + f(i,j+1,n)mod)mod;
}
int main(){
    int n;
    cin>>n;
    grid.clear();
    dp.clear();
    dp.resize(n,vector<int>(n,-1));
    grid.resize(n,vector<char>(n,' '));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    cout<<f(0,0,n)mod;
    return 0;

}