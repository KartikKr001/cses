#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}

class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};


vector<Edge> kruskalMST(int V, vector<Edge> &edges) {
    vector<Edge> mst;
    DSU dsu(V);

    
    sort(edges.begin(), edges.end(), compareEdges);

    
    for (const Edge &edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            mst.push_back(edge);
            dsu.unite(edge.src, edge.dest);
        }
    }
    
    return mst;
}

int main() {
    int V = 4; 
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    vector<Edge> mst = kruskalMST(V, edges);

    cout << "Minimum Spanning Tree (MST) edges:\n";
    for (const Edge &edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << "\n";
    }

    return 0;
}
