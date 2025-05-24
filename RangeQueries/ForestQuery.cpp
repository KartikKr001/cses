#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    vector<vector<int>> v(n, vector<int>(n));
    vector<vector<int>> pre(n + 1, vector<int>(n + 1, 0));
    
    // Reading the forest map and initializing v
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char cell;
            cin >> cell;
            v[i][j] = (cell == '*') ? 1 : 0;
        }
    }
    
    // Building the prefix sum array
    pre[0][0] = v[0][0];
    for (int i = 1; i < n; i++) pre[i][0] = pre[i-1][0];
    for (int i = 1; i < n; i++) pre[0][i] = pre[0][i-1];

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            pre[i][j] = pre[i][j-1] + pre[i-1][j] + v[i][j];
        }
    }
    // Processing the queries
    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--,r2--,c1--,c2--;
        cout<<pre[max(r1,r2)][max(c1,c2)]-pre[min(r1,r2)][min(c1,c2)]+v[max(r1,r2)][max(c1,c2)]<<endl;   
    }
    
    return 0;
}
