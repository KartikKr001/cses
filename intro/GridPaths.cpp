#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> grid;
string s;
long long ans = 0;
void f(int i,int j,int idx){
    if(i<0 || j<0 || i>=7 || j>=7) return;
    if(grid[i][j]) return;
    if(idx == 48){
        if(i==6 && j==0) ans++;
        return;
    }
    grid[i][j] = true; 
    if(s[idx] == '?'){
        f(i+1,j,idx+1);
        f(i-1,j,idx+1);
        f(i,j+1,idx+1);
        f(i,j-1,idx+1);
    }
    else{
        if(s[idx] == 'D') f(i+1,j,idx+1);
        else if(s[idx] == 'U') f(i-1,j,idx+1);
        else if(s[idx] == 'R') f(i,j+1,idx+1);
        else f(i,j-1,idx+1);
    }
    grid[i][j] = false; 
}   
int main(){
    cin>>s;
    grid.clear();
    grid.resize(7,vector<bool>(7,false));
    f(0,0,0);
    cout<<ans<<endl;
    return 0;
}