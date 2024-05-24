#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

// Union-Find data structure class
class UnionFind {
    vector<int> parent, rank, size;
public:
    // Constructor to initialize the Union-Find structure
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // each element is its own parent (self-rooted)
        }
    }

    // Find function with path compression
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);  // Path compression
        }
        return parent[u];
    }

    // Union function with union by rank
    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            // Union by rank
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
                size[root_v] += size[root_u];
            } else {
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
                rank[root_u]++;
            }
        }
    }

    // Get the size of the component containing node u
    int getSize(int u) {
        return size[find(u)];
    }

    // Get sizes of all distinct components
    vector<int> getComponentSizes() {
        vector<int> componentSizes;
        vector<bool> visited(parent.size(), false);
        for (int i = 0; i < parent.size(); ++i) {
            int root = find(i);
            if (!visited[root]) {
                visited[root] = true;
                componentSizes.push_back(size[root]);
            }
        }
        return componentSizes;
    }
};

int main() {
    int n, p, a, b;
    scanf("%d%d", &n, &p);  // Read number of astronauts and number of pairs

    UnionFind uf(n);  // Initialize Union-Find structure

    // Read each pair and unite the astronauts
    for (int i = 0; i < p; ++i) {
        scanf("%d%d", &a, &b);
        uf.unite(a, b);
    }

    // Get the sizes of all components
    vector<int> componentSizes = uf.getComponentSizes();
    
    // Calculate the total number of pairs
    long long totalPairs = (long long)n * (n - 1) / 2;
    
    // Calculate the number of pairs within the same component
    long long sameCountryPairs = 0;
    for (int size : componentSizes) {
        sameCountryPairs += (long long)size * (size - 1) / 2;
    }

    // Subtract same-country pairs from total pairs to get valid pairs
    long long result = totalPairs - sameCountryPairs;
    printf("%lld\n", result);  // Output the result

    return 0;
}
