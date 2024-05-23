#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    
    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }
    
    void union_sets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (size[rootX] < size[rootY]) {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
    
    int get_size(int x) {
        int rootX = find(x);
        return size[rootX];
    }

private:
    vector<int> parent;
    vector<int> size;
};

int main() {
    int n, q;
    cin >> n >> q;
    
    DisjointSet ds(n);
    
    for (int i = 0; i < q; ++i) {
        char queryType;
        cin >> queryType;
        
        if (queryType == 'M') {
            int u, v;
            cin >> u >> v;
            ds.union_sets(u, v);
        } else if (queryType == 'Q') {
            int u;
            cin >> u;
            cout << ds.get_size(u) << endl;
        }
    }
    
    return 0;
}