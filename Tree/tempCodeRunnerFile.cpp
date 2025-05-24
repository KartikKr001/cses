

// const int MAX_N = 2e5;
// vector<int> adj[MAX_N + 1];
// set<int> st[MAX_N + 1];
// int ans[MAX_N + 1];
// void process_st(int node, int par){
//     for (int n : adj[node]) {
//         if (n != par) {
//             process_st(n, node);
//             for (int item : st[n]) {
//                 st[node].insert(item);
//             }
//         }
//     }
//     ans[node] = st[node].size();
// }

