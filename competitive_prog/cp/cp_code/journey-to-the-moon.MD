# journey-to-the-moon

The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

`Example` :

+ n = 4
+ astronaut = [1, 2], [2, 3]

There are 4 astronauts numbered 0 through 3. Astronauts grouped by country are [0] and [1, 2, 3]. There are 3 pairs to choose from: [0, 1], [0, 2] and [0, 3].

`Function Description` :

Complete the journeyToMoon function in the editor below.

journeyToMoon has the following parameter(s):

+ int n: the number of astronauts
+ int astronaut[p][2]: each element astronaut[i] is a 2 element array that represents the ID's of two astronauts from the same country

`Returns` :
- int: the number of valid pairs

`Input Format` :

The first line contains two integers n and p, the number of astronauts and the number of pairs.
Each of the next p lines contains 2 space-separated integers denoting astronaut ID's of two who share the same nationality.

`Constraints` :

$$ 1 \le n \le 10^5 $$
$$ 1 \le p \le 10^4  $$


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
5 3
0 1
2 3
0 4
```
</td>

<td>

```
6
```
</td>
</tr>
</table>

Explanation 0 :

Persons numbered [0, 1, 4] belong to one country, and those numbered [2, 3] belong to another. The UN has 6 ways of choosing a pair: [0, 2], [0, 3], [1, 2], [1, 3], [4, 2], [4, 3].


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
4 1
0 2
```
</td>

<td>

```
5
```
</td>
</tr>
</table>


Explanation 1 :

Persons numbered [0, 2] belong to the same country, but persons 1 and 3 don't share countries with anyone else. The UN has 5 ways of choosing a pair: [0, 1], [0, 3], [1, 2], [1, 3], [2, 3].


```cpp
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
```

## Detailed Explanation :

### `Union-Find Data Structure`:

+ `Initialization`: The constructor initializes three vectors: `parent`, `rank`, and `size`.
  + `parent[i]` is initially set to `i`, meaning each element is its own parent.
  + `rank` is used to keep the tree flat by always attaching the smaller tree under the root of the larger tree.
  + `size` keeps track of the size of each component (number of nodes in each set).
+ `Find Operation`: The `find` function returns the root of the element `u`. It uses path compression, which flattens the structure, making future operations faster.

+ `Union Operation`: The `unite` function merges the sets containing elements `u` and `v`. It uses union by rank to attach the smaller tree under the larger tree, ensuring the tree remains balanced.

### `Main Function`:

+ `Input Reading`: The number of astronauts (`n`) and pairs (`p`) are read using `scanf` for fast input. Each pair is then read and processed.

+ `Union Operation`: For each pair `(a, b)`, the `unite` function is called to merge the sets containing `a` and `b`.

+ `Component Sizes`: The `getComponentSizes` function is called to collect the sizes of all unique components. This function iterates through all elements, finds their root, and records the size of each unique component.

+ `Total Pairs Calculation`: The total number of pairs of astronauts is calculated using the formula `n * (n - 1) / 2`, which is the combination formula `C(n, 2)`.

+ `Same-Country Pairs Calculation`: For each component, the number of pairs within the same component is calculated using the same combination formula applied to the component size.

+ `Valid Pairs Calculation`: The number of valid pairs is obtained by subtracting the same-country pairs from the total pairs.

+ `Output`: The result is printed using `printf`.

This optimized version ensures efficient operations for union and find using path compression and union by rank, making the solution scalable for large inputs.



