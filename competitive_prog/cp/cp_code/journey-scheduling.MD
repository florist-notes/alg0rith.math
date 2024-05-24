# journey-scheduling

Fedya is a seasoned traveller and is planning his trip to Treeland. Treeland is a country with an ancient road system which is in the form of a tree structure. N cities of Treeland are numbered by N positive integers: 1, 2, 3,..., N.

Fedya has not yet decided the starting point (city) of his journey and the cities he will visit. But there are a few things you know about Fedya's trip:

+ Fedya is fond of travelling to great distances. So if he is currently located in city V, his destination will be a city which is most distant from city V.

+ There might be more than 1 such cities. In that case, Fedya will choose a city that was already visited as less times as possible in this journey.

+ There still might be more than 1 such cities. In that case, Fedya will go to the city with the smallest number.

Fedya has prepared a list of M possible journeys. Each one is characterized by two integers - the starting city V and the total number of cities to be visited, K. For each of them, he is keen to know the total distance travelled by him.

`Input Format` :

The first line of input will contain two space separated integers N and M - the number of cities and the number of possible journeys.

Then, there will be (N-1) lines, each of them will contain two space separated integers X Y, denoting the bi-directional road between the cities with numbers X and Y with the unitary length.

Then there will be M lines, each of them will have two space separated integers V and K, denoting a journey.

`Constraints``:

$$ 1 \le N, M \le 10^5 $$
$$ 1 \le V,X,Y \le N $$
$$ 1 \le K \le 10^9 $$

`Output Format `: For each journey, output the travelled distance on a separate line.


<table width=100%>
<tr>
<th>Sample Input :</th>
<th>Sample Output :</th>
</tr>

<tr>
<td>

```
8 7
2 1
3 2
4 2
5 1
6 1
7 1
8 7
4 6
3 4
6 3
7 6
4 6
7 1
2 6
```
</td>

<td>

```
24
16
11
23
24
3
23
```
</td>
</tr>
</table>

`Explanation` :

The tree in question is given in the picture below.

<img src="img/tree.png" width=100%>

+ 4 6 indicates that Fedya starts at 4. Now we see that the most distant city from 4 is 8. Fedya now travels to city 8. From 8, the most distance cities are [4, 3]. As 4 is already visited, he chooses to visit city 3. From city 3, he revisits city 8 and so on. The cities in the order of visit is 4 - > 8 -> 3 -> 8 -> 4 -> 8 -> 3 which sums to 24. Hence, the answer.

+ 6 3 indicates that Fedya starts at city 6. From 6, the most distant cities are [3,4,8]. In this leg of the journey, no city is visited and hence Fedya chooses to visit the city with the smallest number 3. From 3, he visits 8 and then he ends his trip at city 4 which sums to 3 + 4 + 4 = 11. Hence, the answer.

## Solution :

```cpp
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
```

+  Libraries and Namespace :

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
```

Here, we include necessary header files for input/output (`iostream`), dynamic arrays (`vector`), associative arrays (`map`), and algorithms (`algorithm`). We then declare that we're using the std namespace to avoid prefixing standard library elements.

+ Global Variables :

```cpp
vector<int> visited;
int max_length = 0;
```
+ DESC :  
  + `visited`: A vector to keep track of visited nodes during DFS.
  + `max_length`: To store the maximum length found during DFS.


+  Depth-First Search (DFS) Function :
```cpp
int perform_dfs(vector<map<int, int>>& graph, int node, int current_dist)
```
This function performs a Depth-First Search (DFS) traversal on the tree graph to calculate the maximum distance from each node. It returns the maximum depth of the subtree rooted at `node`.

+ Main Function :
```cpp
int main() {
    int num_cities, num_journeys;
    cin >> num_cities >> num_journeys;

    vector<map<int, int>> graph(num_cities);
    for (int i = 0; i < num_cities - 1; ++i) {
        int city1, city2;
        cin >> city1 >> city2;
        --city1; --city2; // Convert to zero-based index
        graph[city1][city2] = 0;
        graph[city2][city1] = 0;
    }
```
+ DESC :
    + Read the number of cities (`num_cities`) and the number of journeys (`num_journeys`).
    + Create a graph represented as an adjacency list of maps (`graph`) to store connections between cities.
    + Populate the graph by reading `num_cities - 1` pairs of integers representing the connections between cities.

+ Depth-First Search (DFS) Calls :
```cpp
    visited.assign(num_cities, 0);
    perform_dfs(graph, 0, 0);

    visited.assign(num_cities, 0);
    perform_dfs(graph, 0, 0);
```
+ DESC :
    + Initialize the `visited` array with zeros to mark unvisited nodes.
    + Perform two DFS calls starting from node `0`. The first call calculates distances and updates the graph, while the second call finds the maximum depth in the tree.

+ Journey Processing :

```cpp
    while (num_journeys--) {
        int start_city;
        long long num_visits;
        cin >> start_city >> num_visits;
        --start_city; // Convert to zero-based index

        int max_dist = 0;
        for (const auto& [neighbor, distance] : graph[start_city]) {
            max_dist = max(max_dist, distance);
        }

        long long total_distance = max_dist + (num_visits - 1) * max_length;
        cout << total_distance << endl;
    }
```
+ Process each journey:
    + Read the starting city (`start_city`) and the number of visits (`num_visits`).
    + Calculate the maximum distance (`max_dist`) from the starting city to any other city.
    + Calculate the total distance travelled using the formula `max_dist + (num_visits - 1) * max_length`, where `max_length` is the maximum distance found in the tree.
    + Output the total distance travelled for each journey.

This code efficiently calculates the total distance travelled for each journey in the given tree structure. It utilizes DFS to compute distances and then simulates journeys based on the calculated distances. The use of maps allows for efficient storage of connections between cities, and the code is well-commented for clarity and readability.