#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

// Constants and macros
#define REP(i, n) for (int i = 0; i < (n); i++)
#define pb push_back

// Constants
const int MAX_CITIES = 10000;
const int MOD = 1000000000;

// Graph representation
vector<int> adj[MAX_CITIES];  // Adjacency list for the main graph
vector<int> reverseAdj[MAX_CITIES];  // Adjacency list for the reversed graph

// Visited arrays for DFS
bool visitedFromStart[MAX_CITIES];  // Visited array for DFS from the start city
bool visitedFromEnd[MAX_CITIES];    // Visited array for DFS from the end city
bool visited[MAX_CITIES];           // General visited array for path counting

// DP memoization array
int memo[MAX_CITIES];

// Number of cities
int numCities;

// Function to read integers from input
int readInt() {
    int x;
    scanf("%d", &x);
    return x;
}

// DFS function to mark reachable nodes
void dfs(vector<int> graph[], bool visited[], int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(graph, visited, neighbor);
        }
    }
}

// Function to count paths using postorder traversal
int countPaths(int node) {
    if (memo[node] != -1) {
        return memo[node];
    }

    int pathCount = 0;
    visited[node] = true;

    if (node == numCities - 1) {
        pathCount = 1;
    } else {
        for (int neighbor : adj[node]) {
            if (visitedFromStart[neighbor] && visitedFromEnd[neighbor]) {
                if (visited[neighbor]) {
                    throw 0;  // Cycle detected, leading to infinite paths
                }
                pathCount = (pathCount + countPaths(neighbor)) % MOD;
            }
        }
    }

    visited[node] = false;
    return memo[node] = pathCount;
}

int main() {
    numCities = readInt();
    int numEdges = readInt();

    // Read edges and construct the graph
    REP(i, numEdges) {
        int u = readInt() - 1;
        int v = readInt() - 1;
        adj[u].pb(v);
        reverseAdj[v].pb(u);
    }

    // Perform DFS from the start city (city 0) and the end city (city numCities-1)
    dfs(adj, visitedFromStart, 0);
    dfs(reverseAdj, visitedFromEnd, numCities - 1);

    // Initialize memo array with -1 (indicating uncomputed states)
    fill_n(memo, numCities, -1);

    // Try to compute the number of paths from city 0 to city numCities-1
    try {
        printf("%d\n", countPaths(0));
    } catch (...) {
        puts("INFINITE PATHS");
    }

    return 0;
}
