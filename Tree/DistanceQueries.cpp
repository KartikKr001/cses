#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<int>par(n+1,-1);
    vector<int>level(n+1,0);
    vector<list<int>>graph(n+1,list<int> ());
    int a,b;
    par[1] = 1;
    level[1] = 1;
    int e = n-1;
    while(e--){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    queue<int>qu;
    qu.push(1);
    while(qu.size() > 0){
        int curr = qu.front();
        qu.pop();
        for(auto x:graph[curr]){
            if(x!= 1 && par[x] == -1){
                par[x] = curr;
                level[x] = level[curr]+1;
                qu.push(x);
            }
        }
    }

    while(q--){
        cin>>a>>b;
        int dist = 0;
        while(level[a] > level[b]){
            dist++;
            a = par[a];
        }
        while(level[b] > level[a]){
            dist++;
            b = par[b];
        }
        if(a == b){
            cout<<dist<<endl;
            continue;
        }
        // not same parent
        while(par[a] != par[b]){
            dist += 2;
            a = par[a];
            b = par[b];
        }
        // have same parent
        if(par[a] == par[b]) dist+=2;
        // else they are same
        cout<<dist<<endl;
    }

    // for(int i=1;i<=n;i++) cout<<par[i]<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++) cout<<level[i]<<" ";
    return 0;
}