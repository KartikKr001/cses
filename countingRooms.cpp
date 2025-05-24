#include<bits/stdc++.h>
using namespace std;
vector<int>dx={1,-1,0,0};
vector<int>dy={0,0,1,-1};
void dfs(vector<vector<char>>&graph,int x,int y){
    for(int i=0;i<4;i++){
        int newx = x+dx[i];
        int newy = y+dy[i];
        if(newx>=0 && newy>=0 && newx<graph.size() && newy<graph[0].size()){
            if(graph[newx][newy] == '.'){
                graph[newx][newy] = '-';
                dfs(graph,newx,newy);
            }
        }
    }
    return;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v(n,vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }

    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(v[i][j] == '.'){
                dfs(v,i,j);
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}   