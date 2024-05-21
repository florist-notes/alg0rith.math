# Advanced Graph Algorithms

NOTES : [graph_theory.MD](./graph_base.MD) 🌸

##  Strong Connectivity

+ `Definition`: A directed graph is strongly connected if there is a path from any vertex to every other vertex. In other words, for every pair of vertices (u, v), there should be a directed path from u to v and a directed path from v to u.

+ `Finding Strongly Connected Components (SCCs)`: To find all the SCCs in a graph, we can use Kosaraju's Algorithm.

### `Kosaraju's Algorithm`
Steps:

+ Perform a DFS (Depth First Search) on the original graph to get a finishing order of the vertices.
+ Reverse all the edges of the graph to get the transpose graph.
+ Perform DFS on the transpose graph, starting from the vertices in the order obtained from the first DFS (in decreasing order of their finishing times).

C++ Code Example:

```python
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list
    vector<vector<int>> adjT; // Transpose adjacency list
    
    void DFS1(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                DFS1(u, visited, Stack);
        }
        Stack.push(v);
    }
    
    void DFS2(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adjT[v]) {
            if (!visited[u])
                DFS2(u, visited);
        }
    }

public:
    Graph(int V) : V(V), adj(V), adjT(V) {}
    
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void findSCCs() {
        stack<int> Stack;
        vector<bool> visited(V, false);
        
        // First DFS to get finishing times
        for (int i = 0; i < V; i++)
            if (!visited[i])
                DFS1(i, visited, Stack);
        
        // Create transpose graph
        for (int v = 0; v < V; v++) {
            for (int u : adj[v]) {
                adjT[u].push_back(v);
            }
        }
        
        // Second DFS based on finishing times
        fill(visited.begin(), visited.end(), false);
        
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v]) {
                DFS2(v, visited);
                cout << endl;
            }
        }
    }
};

int main() {
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Strongly Connected Components:\n";
    g.findSCCs();

    return 0;
}
```

### `2SAT Problem` :

+ `Definition`: The 2-Satisfiability (2SAT) problem is a special case of the Boolean satisfiability problem (SAT), where each clause in the formula is limited to at most two literals. It can be efficiently solved in polynomial time using graph theory techniques.

+ `Reduction to Implication Graph` :

1. Create an implication graph where each variable and its negation are nodes.
2. For each clause (a ∨ b), add two implications:

+ ¬a ⇒ b
+ ¬b ⇒ a
  
`Solution using SCCs`: To determine if a 2SAT instance is satisfiable, we need to ensure that no variable and its negation are in the same SCC.

C++ Code Example:

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;

class TwoSAT {
    int V; // Number of variables
    vector<vector<int>> adj;
    vector<vector<int>> adjT;
    
    void DFS1(int v, vector<bool>& visited, stack<int>& Stack) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u])
                DFS1(u, visited, Stack);
        }
        Stack.push(v);
    }
    
    void DFS2(int v, vector<bool>& visited, vector<int>& component) {
        visited[v] = true;
        component.push_back(v);
        for (int u : adjT[v]) {
            if (!visited[u])
                DFS2(u, visited, component);
        }
    }
    
public:
    TwoSAT(int V) : V(V), adj(2 * V), adjT(2 * V) {}
    
    void addClause(int a, int b) {
        adj[a ^ 1].push_back(b); // ¬a ⇒ b
        adj[b ^ 1].push_back(a); // ¬b ⇒ a
        adjT[b].push_back(a ^ 1); // For transpose graph
        adjT[a].push_back(b ^ 1); // For transpose graph
    }
    
    bool isSatisfiable(vector<int>& result) {
        stack<int> Stack;
        vector<bool> visited(2 * V, false);
        
        // First pass to get finishing times
        for (int i = 0; i < 2 * V; i++)
            if (!visited[i])
                DFS1(i, visited, Stack);
        
        // Second pass to find SCCs
        fill(visited.begin(), visited.end(), false);
        vector<int> component;
        vector<int> id(2 * V, -1);
        int index = 0;
        
        while (!Stack.empty()) {
            int v = Stack.top();
            Stack.pop();
            if (!visited[v]) {
                DFS2(v, visited, component);
                for (int u : component) {
                    id[u] = index;
                }
                index++;
                component.clear();
            }
        }
        
        // Check for satisfiability
        result.resize(V);
        for (int i = 0; i < V; i++) {
            if (id[2 * i] == id[2 * i + 1]) {
                return false; // ¬x and x are in the same SCC
            }
            result[i] = (id[2 * i] > id[2 * i + 1]);
        }
        return true;
    }
};

int main() {
    TwoSAT ts(3);
    ts.addClause(0, 2);   // x0 ∨ x1
    ts.addClause(1, 3);   // x1 ∨ x2
    ts.addClause(4, 1);   // ¬x2 ∨ x0

    vector<int> result;
    if (ts.isSatisfiable(result)) {
        cout << "Satisfiable\n";
        for (int i = 0; i < result.size(); i++) {
            cout << "x" << i << " = " << result[i] << "\n";
        }
    } else {
        cout << "Not Satisfiable\n";
    }
    
    return 0;
}
```

## Complete Paths

+ `Definition`:
In graph theory, a complete path is a path that visits every vertex in the graph at least once.

For complete paths in directed or undirected graphs, it often refers to paths such as Eulerian or Hamiltonian paths.

###  Eulerian Paths

+ `Definition`:
An Eulerian path is a path in a graph that visits every edge exactly once. If such a path exists and it starts and ends at the same vertex, it is called an Eulerian circuit or Eulerian cycle.

+ `Conditions for Eulerian Path`:

    + `Undirected Graph`: An Eulerian path exists if and only if exactly zero or two vertices have an odd degree.
  
    + `Directed Graph`: An Eulerian path exists if and only if at most one vertex has (out-degree - in-degree) = 1, at most one vertex has (in-degree - out-degree) = 1, and all other vertices have equal in-degree and out-degree.

C++ Code Example for Finding Eulerian Path in an Undirected Graph:

```cpp
#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

class Graph {
    int V;
    list<int> *adj;

public:
    Graph(int V) : V(V) {
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isEulerianPath() {
        vector<int> degree(V, 0);

        // Calculate degrees of all vertices
        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                degree[u]++;
            }
        }

        int odd = 0;
        for (int i = 0; i < V; i++) {
            if (degree[i] % 2 != 0)
                odd++;
        }

        // If odd degree count is more than two, return false
        if (odd > 2)
            return false;

        return true;
    }

    void DFS(int v, vector<bool>& visited) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (!visited[u]) {
                DFS(u, visited);
            }
        }
    }

    bool isConnected() {
        vector<bool> visited(V, false);

        int i;
        for (i = 0; i < V; i++) {
            if (adj[i].size() != 0)
                break;
        }

        if (i == V)
            return true;

        DFS(i, visited);

        for (i = 0; i < V; i++) {
            if (!visited[i] && adj[i].size() > 0)
                return false;
        }

        return true;
    }

    void printEulerianPath() {
        if (!isEulerianPath() || !isConnected()) {
            cout << "No Eulerian Path exists" << endl;
            return;
        }

        unordered_map<int, list<int>::iterator> edgeIterators;
        for (int i = 0; i < V; i++) {
            edgeIterators[i] = adj[i].begin();
        }

        list<int> currPath;
        vector<int> circuit;

        int currV = 0;
        currPath.push_back(currV);

        while (!currPath.empty()) {
            if (edgeIterators[currV] != adj[currV].end()) {
                currPath.push_back(currV);

                int nextV = *edgeIterators[currV];
                edgeIterators[currV]++;
                adj[currV].remove(nextV);
                adj[nextV].remove(currV);
                currV = nextV;
            } else {
                circuit.push_back(currV);
                currV = currPath.back();
                currPath.pop_back();
            }
        }

        for (int i = circuit.size() - 1; i >= 0; i--) {
            cout << circuit[i];
            if (i)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(0, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);

    g.printEulerianPath();

    return 0;
}
```

### Hamiltonian Paths

+ `Definition`:
A Hamiltonian path is a path in a graph that visits each vertex exactly once. If such a path exists and it starts and ends at the same vertex, it is called a Hamiltonian cycle.

+ `Finding Hamiltonian Path`:
Unlike Eulerian paths, there are no simple necessary and sufficient conditions for the existence of Hamiltonian paths. Finding such paths is NP-complete.

C++ Code Example for Finding Hamiltonian Path:

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

    bool isSafe(int v, vector<int>& path, int pos) {
        if (find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), v) == adj[path[pos - 1]].end())
            return false;

        for (int i = 0; i < pos; i++)
            if (path[i] == v)
                return false;

        return true;
    }

    bool hamCycleUtil(vector<int>& path, int pos) {
        if (pos == V) {
            if (find(adj[path[pos - 1]].begin(), adj[path[pos - 1]].end(), path[0]) != adj[path[pos - 1]].end())
                return true;
            else
                return false;
        }

        for (int v = 1; v < V; v++) {
            if (isSafe(v, path, pos)) {
                path[pos] = v;

                if (hamCycleUtil(path, pos + 1) == true)
                    return true;

                path[pos] = -1;
            }
        }

        return false;
    }

public:
    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printHamCycle() {
        vector<int> path(V, -1);

        path[0] = 0;
        if (hamCycleUtil(path, 1) == false) {
            cout << "No Hamiltonian Cycle exists" << endl;
            return;
        }

        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0] << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    g.addEdge(1, 3);

    g.printHamCycle();

    return 0;
}
```
