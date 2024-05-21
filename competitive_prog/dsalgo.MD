# 🌸 Data Structure and Algorithms in c++

[ [Stanford : Algorithms](https://www.coursera.org/account/accomplishments/specialization/MLPWX6Q7QDPE), [UCSD : Data Structure and Algorithms](https://www.coursera.org/account/accomplishments/specialization/X4SKMS9Y4AKX) ]

```cpp
#include <iostream>
#include <vector>

// global declarations
// no of nodes max limit.
const int MAX = 1e5;
// adjacency list
std::vector<int> adj[MAX];
std::vector<bool> visited;
std::vector<int> dp;

void depth_first_search(int u) {
    visited[u] = true;
    int child_height = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            depth_first_search(v);

            // select maximum sub-tree height from all children.
            child_height = std::max(child_height, dp[v] + 1);
        }
    }
    // assigned the max child height to current visited node.
    dp[u] = child_height;
}

int main() {
    // number of nodes
    int number_of_nodes;
    std::cout << "Enter number of nodes of the tree : " << std::endl;
    std::cin >> number_of_nodes;

    // u, v denotes an undirected edge of tree.
    int u, v;
    // Tree contains exactly n-1 edges where n denotes the number of nodes.
    std::cout << "Enter edges of the tree : " << std::endl;
    for (int i = 0; i < number_of_nodes - 1; i++) {
        std::cin >> u >> v;
        // undirected tree u -> v and v -> u.
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // initialize all nodes as unvisited.
    visited.assign(number_of_nodes + 1, false);
    // initialize depth of all nodes to 0.
    dp.assign(number_of_nodes + 1, 0);
    // function call which will initialize the height of all nodes.
    depth_first_search(1);
    std::cout << "Height of the Tree : " << dp[1] << std::endl;
}
```

<table width=100%>
<tr>
<th>Sorting and Searching</th>
<th>

Data Structure [[NOTES](./code/ds.MD)]</th>
</tr>
<tr>
<td>

+ Sorting Algorithms [[vis](https://youtu.be/kPRA0W1kECg?si=uO5HzuvqUQRD6kRi), [vid](https://youtu.be/RfXt_qHDEPw?si=lR0mDz9Ea-0vOW21) ]
    + Bubble Sort
    + Merge Sort
    + Sorting Lower Bound
    + Counting Sort
    + Sorting in Practice
+ Solving problems by sorting
    + Sweep Line Algorithms
    + Scheduling Events
    + Tasks and Deadlines
+ Binary Search
    + Implementing the Search
    + Finding Optimal Solutions
</td>
<td>

+ Dynamic Arrays
    + Vectors
    + Iterators and Ranges
    + Other Structures
+ Set Structures
    + Sets and multisets
    + Maps
    + Priority Queues
    + Policy-Based Sets
+ Bitwise
+ Experiments:
    + Set Versus Sorting
    + Map Versus Array
    + Priority Queue Versus Multiset
</td>
</tr>

<tr>
<th>

Dynamic Programming [[NOTES](./code/dynamic_p.MD)]</th>
<th>

Graph Algorithms [ [NOTES](./code/graph_base.MD) ] </th>
</tr>
<tr>
<td>

+ Basic Concepts
    + When Greedy Fails
    + Finding an Optimal Solution
    + Counting Solutions
+ Further Examples
    + Longest Increasing Subsequence
    + Paths in a Grid
    + Knapsack Problems
    + From Permutations to Subsets
    + Counting Tilings
</td>
<td>

+ Basics of Graphs 
    + Graph Terminiology and Representation
+ Graph Traversal
    + Depth First Search (DFS)
    + Breadth First Search (BFS)
    + Applications
+ Shortest Paths
    + Bellman-Ford Algorithm
    + Djikstra's Algorithm
    + Floyd-Warshall Algorithm
+ Directed Acyclic Graphs
    + Topological Sorting
    + Dynamic Programming
+ Successor Graphs
    + Finding Successors
    + Cycle Detection
+ Minimum Spanning Trees
    + Kruskal's Algorithm
    + Union-Find Structure
    + Prim's Algorithm
</td>
</tr>

<tr>
<th>Algorithm design topics</th>
<th>Range Queries</th>
</tr>
<tr>
<td>

+ Bit Parallel Algorithms
    + Hamming Distances
    + Counting Subgrids
    + Reachability in Graphs
+ Amortized Analysis
    + Two Pointers method
    + Nearest Smaller Elements
    + Sliding Window Minimum
+ Finding Minimum Vales
    + Ternary Search
    + Convex Functions
    + Minimizing Sums
</td>
<td>

+ Queries on Static Arrays
    + Sum Queries
    + Minimum Queries
+ Tree Structures
    + Binary Indexed Trees
    + Segment Trees
    + Additional Techniques
</td>
</tr>

<tr>
<th>Tree Algorithms</th>
<th>Mathematics</th>
</tr>
<tr>
<td>

+ Basic Techniques
    + Tree Traversal
    + Calculating Diameters
    + All Longest Paths
+ Tree Queries
    + Finding Ancestors
    + Subtrees and Paths
    + Lowest Common Ancestors
    + Merging Data Structures
+ Advanced Techniques
    + Centroid Decomposition
    + Heavy-Light Deconmposition
</td>
<td>

+ Number Theory [[notes](./code/number_theory.MD)]
    + Primes and Factors
    + Sieve of Erastosthenes
    + Euclid's Algorithm
    + Modular Exponentiation
    + Euler's Theorem
    + Solving Equations
+ Combinatorics [[notes](./code/combinatorics.MD)]
    + Binomial Coefficients
    + Catalan Numbers
    + Inclusion-Exclusion
    + Burnside's Lemma
    + Cayley's Formula
+ Matrices [[notes](./code/matrices.MD)]
    + Matrix Operations
    + Linear Recurrences
    + Graphs and Matrices
    + Gaussian Elimination
+ Probability [[notes](./code/probability.MD)]
    + Working with Events
    + Random Variables
    + Markov Chains
    + Randomized Algorithms
+ Game Theory [[notes](./code/gametheory.MD)]
    + Game States
    + Nim Game
    + Sprague-Grundy Theorem
+ Fourier Transform  [[notes](./code/fft.MD)]
    + Working with Polynomials
    + FFT Algorithm
    + Calculating Convolutions
</td>
</tr>

<tr>
<th>

Advanced Graph Algorithms [[NOTES](./code/graph_advanced.MD)]</th>
<th>Geometry</th>
</tr>
<tr>
<td>

+ Strong Connectivity
    + Kosaraju's Algorithm
    + 2SAT Problem
+ Complete Paths
    + Eulerian Paths
    + Hamiltonian Paths
    + Applications
+ Maximum Flows
    + Ford-Fulkerson Algorithm [ [vid](https://youtu.be/LdOnanfc5TM?si=AwNVmlDPJEBdZhpq), [source_c vid](https://youtu.be/Xu8jjJnwvxE?si=Ge8Hwx9HV9PGxFF0) ]
    + Disjoint Paths
    + Maximum Matchings
    + Path Covers
+ Depth-First Search Trees
    + Biconnectivity
    + Eulerian Subgraphs
+ Minimum Cost Flows [ [vid](https://youtu.be/0tjpC0MCwY8?si=I5QVh5pjfgsvCBuD) ]
    + Minimum Cost Paths Algorithm
    + Minimum Weight Matchings
    + Improving the Algorithm
</td>
<td>

+ Geometric Techniques [[notes](./code/geo/geometric.MD)]
    + Complex Numbers
    + Points and Lines
    + Polygon Area
    + Distance Functions
+ Sweep Line Algorithms [[notes](./code/geo/sweepline.MD)]
    + Intersection Points
    + Closest Pair Problem
    + Convex Hull Problem
</td>
</tr>

<tr>
<th>

String Algorithms [ [Knuth–Morris–Pratt KMP](https://youtu.be/JoF0Z7nVSrA?si=iMPeo4CseACh1LXx) ]</th>
<th>Additional Topics</th>
</tr>
<tr>
<td>

+ Basic Topics
    + Trie Structure
    + Dynamic Programming
+ String Hashing
    + Polynomial Hashing
    + Applications
    + Collisions and Parameters
+ Z-Algorithm   
    + Constructing the Z-Array
    + Applications
+ Suffix Arrays
    + Prefix Doubling Method
    + Finding Patterns
    + LCP Arrays
+ String Automata
    + Regular Languages
    + Pattern Matching Automata
    + Suffix Automata

</td>
<td>

+ Square Root Techniques
    + Data Structures
    + Subalgorithms
    + Integer Partitions
    + Mo's Algorithm
+ Segment Trees Revisited
    + Lazy Propagation
    + Dynamic Trees
    + Data Structures in Nodes
    + Two-Dimensional Trees
+ Treaps
    + Splitting and Merging
    + Implementation
    + Additional Techniques
+ Dynamic Programming Optimization
    + Convex Hull Trick
    + Divide and Conquer Optimization
    + Knuth's Optimization
+ Backtracking Techniques
    + Prunning the Search Tree
    + Heuristic Functions
+ Miscellaneous 
    + Meet in the middle
    + Counting Subsets
    + Parallel Binary Search
    + Dynamic Connectivity
</td>
</tr>
</table>



resources: @github/[cpp-ds-algorithms](https://github.com/TheAlgorithms/C-Plus-Plus), [Looking for a Challenge 2
Problems from the Polish Collegiate
Programming Contest 2011–2014](./cp/looking-for-a-challenge-2-en.pdf), [Guide to Competitive
Programming](https://link.springer.com/book/10.1007/978-3-030-39357-1), [Competitive Programmer’s Handbook](./cp/CPbook.pdf), [C/C++ cheatsheet Documentation](./cp/cppcheatsheet-readthedocs-io-en-latest.pdf), [KTH Royal Institute of Technology Omogen Heap](./cp/kactl.pdf).