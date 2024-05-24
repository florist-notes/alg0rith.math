#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> visited;
int max_length = 0;

// Perform DFS to calculate maximum distance in the tree
int perform_dfs(vector<map<int, int>>& graph, int node, int current_dist) {
    visited[node] = 1;
    int longest_path1 = current_dist, longest_path2 = 0, max_depth = 0;

    // Find the two longest distances from the current node
    for (auto& [neighbor, distance] : graph[node]) {
        if (distance >= longest_path1) {
            longest_path2 = longest_path1;
            longest_path1 = distance;
        } else {
            longest_path2 = max(distance, longest_path2);
        }
    }

    // Update distances for each unvisited neighbor
    for (auto& [neighbor, distance] : graph[node]) {
        if (visited[neighbor]) {
            distance = current_dist;
        } else {
            distance = perform_dfs(graph, neighbor, 1 + (distance != longest_path1 ? longest_path1 : longest_path2));
            max_depth = max(max_depth, distance);
        }
    }

    // Update the maximum length found so far
    max_length = max(max_length, current_dist);
    return max_depth + 1;
}

int main() {
    int num_cities, num_journeys;
    cin >> num_cities >> num_journeys;

    // Build the graph as an adjacency list using a vector of maps
    vector<map<int, int>> graph(num_cities);
    for (int i = 0; i < num_cities - 1; ++i) {
        int city1, city2;
        cin >> city1 >> city2;
        --city1; --city2; // Convert to zero-based index
        graph[city1][city2] = 0;
        graph[city2][city1] = 0;
    }

    // Initialize visited array and perform the first DFS
    visited.assign(num_cities, 0);
    perform_dfs(graph, 0, 0);

    // Re-initialize visited array and perform the second DFS to get the maximum length
    visited.assign(num_cities, 0);
    perform_dfs(graph, 0, 0);

    // Process each journey
    while (num_journeys--) {
        int start_city;
        long long num_visits;
        cin >> start_city >> num_visits;
        --start_city; // Convert to zero-based index

        int max_dist = 0;
        for (const auto& [neighbor, distance] : graph[start_city]) {
            max_dist = max(max_dist, distance);
        }

        // Calculate the total distance for the journey
        long long total_distance = max_dist + (num_visits - 1) * max_length;
        cout << total_distance << endl;
    }

    return 0;
}
