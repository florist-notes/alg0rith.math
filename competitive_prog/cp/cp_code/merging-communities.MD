# merging-communities

`Merging Communities` : In a social network, people form connections with each other. Each connection between Person i and Person j is represented as M i j. When two people from different communities connect, their respective communities merge into a single community.

Initially, there are n people, each representing their own individual community. For instance, if Person 1 connects with Person 2, and then Person 2 connects with Person 3, Persons 1, 2, and 3 will all belong to the same community.

There are two types of queries that can be performed:

+ `M i j`: Merge the communities containing Person i and Person j if they are in different communities.
+ `Q i`: Print the size of the community to which Person i belongs.
  
`Input Format` : 

+ The first line contains two space-separated integers, n and q, where:
  
    + `n` is the number of people.
    + `q` is the number of queries.

+ The next q lines contain the queries, each being either:
  
    + `M i j`: indicating a merge operation.
    + `Q i`: indicating a query to find the size of the community of Person i.

`Constraints` :

+ $$ 1 ≤ 𝑛 ≤ 10^5 $$
+ $$ 1 ≤ q ≤ 2×10^5 $$
 

`Output Format` : For each Q i query, output the size of the community containing Person i.





<table width=100%>
<tr>
<th>Sample Input :</th>
<th>Sample Output :</th>
</tr>

<tr>
<td>

```
3 6
Q 1
M 1 2
Q 2
M 2 3
Q 3
Q 2
```
</td>

<td>

```
1
2
3
3
```
</td>
</tr>
</table>

`Explanation` :
+ Initially, each person's community size is 1.
+ After the first Q 1 query, the size of Person 1's community is 1.
+ The M 1 2 query merges the communities of Person 1 and Person 2.
+ The Q 2 query now shows the size of Person 2's community as 2.
+ The M 2 3 query merges the communities of Persons 2 and 3.
+ The Q 3 and Q 2 queries show that Persons 3 and 2 now belong to a community of size 3.


## 🦩 Solution:

This problem involves efficiently managing and querying dynamic community sizes, often tackled using data structures such as Disjoint Set Union (DSU) or Union-Find.

To solve the problem of merging communities and querying their sizes, we can utilize the Disjoint Set Union (DSU) data structure, also known as Union-Find. This structure is efficient for operations that involve merging sets and finding the representative or size of sets. Here's a detailed step-by-step solution and the corresponding C++ STL code:

### Step-by-Step Solution :
+ `Initialization`:

    + Each person starts in their own community, so initially, we have `n` communities.
    + We maintain two arrays:
      + `parent`: To keep track of the parent of each node.
      + `size`: To keep track of the size of each community.

+ `Union Operation (M i j)`:

    + Merge the communities containing persons `i` and `j`.
    + Use the union by size/rank to keep the tree flat, ensuring efficient operations.

+ `Find Operation`:

    + Find the representative (root) of the community containing a person.
    + Use path compression to speed up future operations by flattening the structure.

+ `Query Operation (Q i)`:

    + Print the size of the community containing person `i`.

```cpp
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
```

### Explanation of the Code :

+ `DisjointSet Class`:

    + The class `DisjointSet` handles the DSU operations.
    + `find(x)`: Implements path compression to find the root of `x`.
    + `union_sets(x, y)`: Merges the sets containing `x` and `y` using union by size.
    + `get_size(x)`: Returns the size of the set containing `x`.

The `DisjointSet class`, also known as Union-Find, is a data structure that keeps track of a partition of a set into disjoint (non-overlapping) subsets.

+ `Main Function`:

    + Reads input values for `n` (number of people) and `q` (number of queries).
    + Processes each query: either merging communities or querying the size of a community.

This approach ensures that both union and find operations are nearly constant time, making the solution efficient even for large values of `n` and `q`.