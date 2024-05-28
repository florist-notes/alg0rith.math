#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Structure to represent an edge
struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        if (weight == other.weight) {
            return (u + v + weight) < (other.u + other.v + other.weight);
        }
        return weight < other.weight;
    }
};

// Find function with path compression
int find(vector<int>& parent, int u) {
    if (parent[u] != u) {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

// Union function by rank
void union_sets(vector<int>& parent, vector<int>& rank, int u, int v) {
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    if (root_u != root_v) {
        if (rank[root_u] > rank[root_v]) {
            parent[root_v] = root_u;
        } else if (rank[root_u] < rank[root_v]) {
            parent[root_u] = root_v;
        } else {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

// Kruskal's algorithm to find MST
int kruskals(int g_nodes, const vector<Edge>& edges) {
    vector<int> parent(g_nodes + 1);
    vector<int> rank(g_nodes + 1, 0);
    iota(parent.begin(), parent.end(), 0);
    
    int mst_weight = 0;
    
    for (const auto& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            union_sets(parent, rank, edge.u, edge.v);
            mst_weight += edge.weight;
        }
    }
    
    return mst_weight;
}

int main() {
    int g_nodes, g_edges;
    cin >> g_nodes >> g_edges;
    
    vector<Edge> edges(g_edges);
    
    for (int i = 0; i < g_edges; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    
    // Sort edges based on the custom comparator defined in the Edge structure
    sort(edges.begin(), edges.end());
    
    // Get the total weight of the MST
    int result = kruskals(g_nodes, edges);
    cout << result << endl;
    
    return 0;
}
