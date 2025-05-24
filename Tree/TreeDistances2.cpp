// https://usaco.guide/problems/cses-1133-tree-distances-ii/solution
#define pp pair<ll,ll>
#define ll long long int
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
vector<vector<ll>>tree;
vector<ll>depth;
vector<ll>dp; // number of nodes in subtree including itself
ll n;
vector<ll>ans; // sum of distance of ith node from root to all other nodes in subtree
void dfs1(ll node,ll par,ll cnt){
    ans[1] += cnt;
    ll sum = 1;
    depth[node] = cnt;
    for(auto x: tree[node]){
        if(x == par) continue;
        dfs1(x,node,cnt+1);
        sum += dp[x];
    }
    dp[node] = sum;
}

// The key observation is that if we reroot the tree at node 1's neighbour (let's say node 2), then

    // The depths of all nodes in node 2's subtree decrease by 1.
    // The depths of all nodes outside of its subtree increase by 1.


// For any node v that is a child of u, the formula follows the same logic:
    // ans[v]=ans[u] + (-dp[v]) + (n−dp[v])

void dfs2(ll node,ll par){
    for(auto x:tree[node]){
        if(x == par) continue;
        ans[x] = ans[node] + (-dp[x]) + (n-dp[x]);
        dfs2(x,node);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    tree.assign(n+1,vector<ll>());
    for(int i=0;i<n-1;i++){
        ll a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    dp.assign(n+1,-1);
    ans.assign(n+1,0);
    depth.assign(n+1,0);
    dfs1(1,-1,0);
    dfs2(1,-1);
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
