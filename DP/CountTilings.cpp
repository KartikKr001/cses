#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>>grid;
vector<vector<int>>dp;
void display(){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int f(int i,int j,int mask){
    cout<<i<<" : "<<j<<endl;
    if(j>=grid.size()) return 1;
    // if(dp[i][j] != -1) return dp[i][j];
    cout<<i<<" : "<<j<<"%% "<<mask<<endl;
    display();
    int ans = 0;
    if(grid[i][j] == false){
        // grid[i][j] = true;
        if(i+1<grid.size()){
            grid[i+1][j] = true;
            ans += f(i+2,j,mask);
            grid[i+1][j] = false;
        }
        if(j+1<grid[0].size()){
            grid[i][j+1] = true;
            mask = mask|(1<<i);

            ans += f(i+2,j,mask);
            grid[i][j+1] = false;
        }
        return dp[i][j] = ans;
    }
    else {
        if(i+1<grid.size()) return dp[i][j] = f(i+1,j,mask);
        else return dp[i][j] = f(0,j+1,mask);
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    grid.clear();
    grid.resize(n,vector<bool>(m,false));
    dp.clear();
    dp.resize(n+10,vector<int>(m+5,-1));
    // cout<<1<<endl;
    cout<<f(0,0,0);
    return 0;
}