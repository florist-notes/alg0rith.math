# 🌸 Graphs

Graph algorithms are an essential part of computer science, and the C++ Standard Template Library (STL) provides various tools to implement them efficiently. Here’s a detailed explanation of how to use C++ STL for graph algorithms, focusing on common representations, algorithms, and practical examples.

Graphs can be represented in several ways. The two most common representations are:

+ `Adjacency List`
+ `Adjacency Matrix`


### + `Adjacency List` :
An adjacency list is a collection of lists or vectors where each list represents a node and contains the nodes that are adjacent to it. This representation is efficient in terms of space, especially for sparse graphs.

```cpp
#include <iostream>
#include <vector>
#include <list>

using namespace std;

// Using vector of lists
vector<list<int>> adjList;

void addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u); // For undirected graph
}

int main() {
    int nodes = 5;
    adjList.resize(nodes);

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    // Display the adjacency list
    for(int i = 0; i < nodes; i++) {
        cout << i << ": ";
        for(auto v : adjList[i])
            cout << v << " ";
        cout << endl;
    }

    return 0;
}
```

### + `Adjacency Matrix` :
An adjacency matrix is a 2D array where the element at row i and column j indicates the presence (and sometimes weight) of an edge between nodes i and j. This is less space-efficient for sparse graphs but can be simpler for dense graphs or when you need to quickly check the existence of an edge.

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjMatrix;

void addEdge(int u, int v) {
    adjMatrix[u][v] = 1;
    adjMatrix[v][u] = 1; // For undirected graph
}

int main() {
    int nodes = 5;
    adjMatrix.resize(nodes, vector<int>(nodes, 0));

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    // Display the adjacency matrix
    for(int i = 0; i < nodes; i++) {
        for(int j = 0; j < nodes; j++)
            cout << adjMatrix[i][j] << " ";
        cout << endl;
    }

    return 0;
}
```

### Common Graph Algorithms :
+ Depth-First Search (DFS)
+ Breadth-First Search (BFS)
+ Dijkstra’s Shortest Path Algorithm
+ Prim’s and Kruskal’s Minimum Spanning Tree Algorithms

<table width=100%>
<tr>
<th>Depth-First Search (DFS)</th>
<th>Breadth-First Search (BFS)</th>
</tr>

<tr>
<td>

DFS is a traversal algorithm that starts at a source node and explores as far as possible along each branch before backtracking.

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adjList;
vector<bool> visited;

void DFS(int v) {
    visited[v] = true;
    cout << v << " ";

    for(int u : adjList[v]) {
        if(!visited[u]) {
            DFS(u);
        }
    }
}

int main() {
    int nodes = 5;
    adjList.resize(nodes);
    visited.resize(nodes, false);

    adjList[0] = {1, 4};
    adjList[1] = {0, 2, 3, 4};
    adjList[2] = {1, 3};
    adjList[3] = {1, 2, 4};
    adjList[4] = {0, 1, 3};

    cout << "DFS starting from node 0: ";
    DFS(0);

    return 0;
}
```

</td>
<td>

BFS is a traversal algorithm that starts at a source node and explores all of the neighbor nodes at the present depth before moving on to nodes at the next depth level.

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;

void BFS(int start) {
    vector<bool> visited(adjList.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";

        for(int u : adjList[v]) {
            if(!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int nodes = 5;
    adjList.resize(nodes);

    adjList[0] = {1, 4};
    adjList[1] = {0, 2, 3, 4};
    adjList[2] = {1, 3};
    adjList[3] = {1, 2, 4};
    adjList[4] = {0, 1, 3};

    cout << "BFS starting from node 0: ";
    BFS(0);

    return 0;
}
```
</td>
</tr>
</table>

## Dijkstra’s Shortest Path Algorithm:

Dijkstra’s algorithm finds the shortest path from a source node to all other nodes in a graph with non-negative weights.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<pair<int, int>>> adjList;

void Dijkstra(int start) {
    int n = adjList.size();
    vector<int> dist(n, numeric_limits<int>::max());
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while(!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;
    }
}

int main() {
    int nodes = 5;
    adjList.resize(nodes);

    adjList[0].push_back({1, 10});
    adjList[0].push_back({4, 3});
    adjList[1].push_back({2, 2});
    adjList[1].push_back({4, 4});
    adjList[2].push_back({3, 9});
    adjList[3].push_back({2, 7});
    adjList[4].push_back({1, 1});
    adjList[4].push_back({2, 8});
    adjList[4].push_back({3, 2});

    Dijkstra(0);

    return 0;
}
```

## Minimum Spanning Tree Algorithms :

+ `Prim’s Algorithm` : Prim’s algorithm finds a minimum spanning tree for a weighted undirected graph.

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

vector<vector<pair<int, int>>> adjList;

void Prim(int start) {
    int n = adjList.size();
    vector<int> key(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    vector<bool> inMST(n, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    key[start] = 0;

    while(!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for(auto edge : adjList[u]) {
            int v = edge.first;
            int weight = edge.second;

            if(!inMST[v] && weight < key[v]) {
                key[v] = weight;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }

    for(int i = 1; i < n; i++) {
        cout << "Edge: " << parent[i] << " - " << i << " with weight " << key[i] << endl;
    }
}

int main() {
    int nodes = 5;
    adjList.resize(nodes);

    adjList[0].push_back({1, 2});
    adjList[0].push_back({3, 6});
    adjList[1].push_back({0, 2});
    adjList[1].push_back({2, 3});
    adjList[1].push_back({3, 8});
    adjList[1].push_back({4, 5});
    adjList[2].push_back({1, 3});
    adjList[2].push_back({4, 7});
    adjList[3].push_back({0, 6});
    adjList[3].push_back({1, 8});
    adjList[4].push_back({1, 5});
    adjList[4].push_back({2, 7});

    Prim(0);

    return 0;
}
```


Resources : [ [Introduction to Graph Theory: A Computer Science Perspective](https://youtu.be/LFKZLXVO-Dg?si=CH1zoLn49chtaoAA), [Graph Algorithms for Technical Interviews - Full Course](https://youtu.be/tWVWeAqZ0WU?si=OvQO2VYMWHkr-kiw), [Breadth First Search (BFS): Visualized and Explained](https://youtu.be/xlVX7dXLS64?si=rlRNaS537lY9dc1n), [Depth First Search (DFS) Explained: Algorithm, Examples, and Code](https://youtu.be/PMMc4VsIacU?si=ZMZJteKYkrch-BIA), Graph Series - [striver playlist](https://www.youtube.com/watch?v=M3_pLsDdeuU&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn), Graph Algorithms - [Playlist](https://www.youtube.com/watch?v=ddTC4Zovtbc&list=PLrmLmBdmIlpu2f2g8ltqaaCZiq6GJvl1j), [Topological Sort Algorithm | Graph Theory](https://youtu.be/eL-KzMXSXXI?si=Tnwkv972_rRgxKMv), [Graph Theory Playlist - WilliamFiset](https://www.youtube.com/watch?v=DgXR2OWQnLc&list=PLDV1Zeh2NRsDGO4--qE8yH72HFL1Km93P), [Graph Series](https://www.youtube.com/watch?v=EaK6aslcC5g&list=PLDzeHZWIZsTobi35C3I-tKB3tRDX6YxuA) ]
