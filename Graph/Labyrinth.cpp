#define pp pair<int,int> 
#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> graph;
vector<vector<bool>> vis;
vector<vector<pp>> parent;
vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,1,-1};
string s="";
bool isValid(int x,int y){
    if(x<0 || y<0 || x>=graph.size() || y>=graph[0].size()){
        return false;
    }
    return true;
}
void bfs(int i,int j,string path){
    queue<pp>q;
    q.push({i,j});
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
        int x = curr.first;
        int y = curr.second;
        if(vis[x][y]) continue;
        if(graph[x][y] == '#') continue;
        if(graph[x][y] =='B'){
            // fetching required path
            string path = "";
            while(x!=i && y!=j){
                if(parent[x][y].first == x){
                    if(parent[x][y].first == x-1){
                        path = 'U'+ path;
                    }
                    else{
                        path = 'D' + path;
                    }
                }
                else{
                    if(parent[x][y].second == y-1){
                        path = 'L'+ path;
                    }
                    else{
                        path = 'R' + path;
                    }
                }
                x=parent[x][y].first;
                y=parent[x][y].second;
            }
            s = path;
            return;
        }
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int nx = dx[i]+x;
            int ny = dy[i]+y;

            if(isValid(nx,ny)){
                parent[nx][ny] = {x,y};
                q.push({nx,ny});
            }
        }
    }
    return ;

}

int main(){
    int n,m;
    cin>>n>>m;
    graph.clear();
    graph.resize(n+1,vector<char>(m+1,'#'));
    vis.clear();
    vis.resize(n+1,vector<bool>(m+1,false));
    parent.clear();
    parent.resize(n+1,vector<pp>(m+1,{-1,-1}));
    int si = 0,sj = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j] == 'A'){
                graph[i][j] == '.';
                si = i;
                sj = j;
            }
        }
    } 
    bfs(si,sj,"");
    if(s == ""){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl<<s.size()<<endl<<s<<endl;
    }
    return 0;
}