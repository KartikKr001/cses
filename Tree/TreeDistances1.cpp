#include<bits/stdc++.h>
#define pp pair<int,int>
using namespace std;
vector<list<int>> tree;
pp bfs(int src,vector<int>&dist){
    int maxL = 0;
    int nod = src;
    queue<int>q;
    dist[src] = 0;
    q.push(src);
    while(q.size()>0){
        auto curr = q.front();
        q.pop();
        for(auto x:tree[curr]){
            if(dist[x] == -1){
                dist[x] = dist[curr]+1;
                q.push(x);
                if(dist[curr] + 1 > maxL) {
                    maxL = dist[curr]+1;
                    nod = x;
                }
            }
        }
    }
    return {nod,maxL};
}
int main(){
    int n;
    cin>>n;
    int e = n-1;
    tree.assign(n+1,list<int>());
    int a,b;
    while(e--){
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }


    vector<int>dist1(n+1,-1);
    vector<int>dist2(n+1,-1);
    // finding one end of tree
    pp one_end = bfs(1,dist1);
    // storing distances in dist1 vector
    dist1.assign(n+1,-1);
    pp two_end = bfs(one_end.first,dist1);
    // finding another end

    // finding distances from second end in dist1 vector
    bfs(two_end.first,dist2);


    
    for(int i=1;i<=n;i++){
        cout<<max(dist1[i],dist2[i])<<" ";
    }

    return 0;
}