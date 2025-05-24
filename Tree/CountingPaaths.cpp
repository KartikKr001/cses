#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> tree[MAXN];
int contribution[MAXN], subtree_sum[MAXN];

void dfs(int node, int parent) {
    subtree_sum[node] = contribution[node];  // Start with the current contribution
    for (int child : tree[node]) {
        if (child != parent) {
            dfs(child, node);
            subtree_sum[node] += subtree_sum[child];  // Accumulate child contributions
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // Read the tree edges
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    // Process paths
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        contribution[a]++;  // Start of path
        contribution[b]++;  // End of path
    }

    // Run DFS to calculate subtree sums
    dfs(1, -1);

    // Print the result
    for (int i = 1; i <= n; i++) {
        cout << subtree_sum[i] << " ";
    }
    cout << "\n";

    return 0;
}
