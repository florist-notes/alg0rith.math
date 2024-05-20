# Dynamic Programming

 Dynamic Programming (DP) is a powerful technique for solving optimization problems by breaking them down into simpler subproblems and storing the solutions to these subproblems to avoid redundant computations. It is particularly useful for problems with overlapping subproblems and optimal substructure.

 ### Key Concepts of Dynamic Programming :
+ `Overlapping Subproblems`: The problem can be broken down into subproblems which are reused multiple times.
+ `Optimal Substructure`: The optimal solution of the problem can be constructed from optimal solutions of its subproblems.
+ `Memoization (Top-Down)`: Recursively solve subproblems and store their results.
+ `Tabulation (Bottom-Up)`: Iteratively solve subproblems and build up the solution in a table.

### Example Problems and Solutions :

🌸 `Fibonacci Sequence` : The Fibonacci sequence is a classic example of a DP problem. The  𝑛-th Fibonacci number is defined as:

$$ F(n) = F(n-1) + F(n-2) $$

with base cases F( 0 ) = 0 and F( 1 ) = 1.

<table width=100%>
<tr>
<th>Recursive Solution with Memoization (Top-Down)</th>
<th>Iterative Solution with Tabulation (Bottom-Up)</th>
</tr>

<tr>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

vector<int> memo;

int fib(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main() {
    int n = 10;
    memo.assign(n + 1, -1);
    cout << "Fibonacci("<< n <<") = "<<fib(n)<<endl;
    return 0;
}
```

</td>
<td>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int fib(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    int n = 10;
    cout << "Fibonacci("<< n <<") = "<<fib(n)<<endl;
    return 0;
}
```
</td>
</tr>
</table>

`memo.assign(n + 1, -1)`: Initializes the `memo` vector with `n+1` elements, all set to `-1`. This indicates that no Fibonacci numbers have been computed yet. We use `n+1` to ensure the vector has a slot for each Fibonacci number from 0 to `n`.

🌸 `0/1 Knapsack Problem` : Given a set of items, each with a weight and a value, determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and the total value is as large as possible. Each item can either be taken (1) or not taken (0), hence the name 0/1 Knapsack Problem.

DP Solution with Tabulation:

+ Initialize `dp[i][0]` = 0 for all i (if the capacity is 0, the value is 0).
+ Initialize `dp[0][w]` = 0 for all w (if there are no items, the value is 0).

<pre>
    <code>
    For each item i (from 1 to n):
        For each capacity w (from 1 to W):
            If the weight of the item i is less than or equal to w:
                dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])
            Else:
                dp[i][w] = dp[i-1][w]
</code>
</pre>

The value at `dp[n][W]` will be the maximum value that can be achieved with `n` items and capacity `W`.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int knapsack(int W, const vector<int>& wt, const vector<int>& val, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (wt[i-1] <= w) {
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            } else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int W = 50;
    vector<int> wt = {10, 20, 30};
    vector<int> val = {60, 100, 120};
    int n = wt.size();
    
    cout << "Maximum value in knapsack = " << knapsack(W, wt, val, n) << endl;
    return 0;
}
```

+ `vector<vector<int>>` : This declares a 2D vector, which is essentially a vector of vectors.
`dp` is the name of this 2D vector. 

+ `dp(n + 1, vector<int>(W + 1, 0))` : This initializes the 2D vector dp with dimensions (n + 1) x (W + 1). `n + 1` is the number of rows. We add 1 to n to account for the case when no items are included (i = 0) and similarly for w.

+ `vector<int>(W + 1, 0)` : This is the constructor for a vector of integers with size `W + 1`, where all elements are initialized to 0. Each element in this vector represents the maximum value achievable with a specific capacity of the knapsack.

+ `dp(n + 1, ...)` : This constructs the outer vector, which contains `n + 1` elements. Each of these elements is itself a vector of size `W + 1` initialized to 0.

+ Filling the DP Table :
  
  + `dp[i][w]` will store the maximum value achievable with the first i items and capacity w.
  + `if (weights[i - 1] <= w) {` : This condition checks if the weight of the current item i (which is `weights[i - 1]` because our item indices start from 0) is less than or equal to the current capacity `w`. If `weights[i - 1] <= w`, it means the current item can potentially be included in the knapsack.
  + If the Item Can Be Included : 
  ```
    + Exclude the item: The value is the same as dp[i - 1][w], which means the maximum value without considering the current item.

    + Include the item: The value is dp[i - 1][w - wt[i - 1]] + val[i - 1], which means we add the current item's value to the maximum value that can be obtained with the remaining capacity (w - weights[i - 1]).
  ``` 
  We take the maximum of these two values to get the best value possible for `dp[i][w]`.

  + If the Item Cannot Be Included : `dp[i][w] = dp[i-1][w]` : If the current item's weight exceeds the current capacity `w`, it cannot be included, so we just carry forward the value without including this item.


🌸 `Longest Increasing Subsequence (LIS) :` Given an array of integers, find the length of the longest subsequence such that all elements of the subsequence are sorted in increasing order. Given an array of integers, the goal is to find the length of the longest subsequence that is strictly increasing. A subsequence is a sequence derived by deleting some or none of the elements from the array without changing the order of the remaining elements.

Given the array `[10, 22, 9, 33, 21, 50, 41, 60, 80]`, one of the longest increasing subsequences is `[10, 22, 33, 50, 60, 80]`, which has a length of 6.

The idea is to use a dynamic programming array `dp` where `dp[i]` represents the length of the longest increasing subsequence that ends with the element at index `i`.

<pre>
<code>
        For each element `arr[i]` in the array (starting from the second element):
            Check all elements before it (`arr[j]` where `j < i`).
            If `arr[j] < arr[i]`, then `arr[i]` can be appended to the increasing subsequence ending at `arr[j]`.
            Update `dp[i]` to `max(dp[i], dp[j] + 1)`.
</code>
</pre>


```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(const vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n, 1);  // Initialize LIS values for all indexes as 1
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    cout << "Length of LIS = " << lis(arr) << endl;
    return 0;
}
```

Resources : [ Video : [5 Simple Steps for Solving Dynamic Programming Problems](https://youtu.be/aPQY__2H3tE?si=5E-UJDxwCPKKrxC7), Mastering Dynamic Programming - How to solve any interview problem - [(Part 1)](https://youtu.be/Hdr64lKQ3e4?si=gyxiDKqWIzPo_EGx), [(Part 2)](https://youtu.be/rE5h11FwiVw?si=Bv5AKug6xIZOJjwV), NeetCode - [Dynamic Programming](https://www.youtube.com/watch?v=g0npyaQtAQM&list=PLot-Xpze53lcvx_tjrr_m2lgD2NsRHlNO), [Dynamic Programming - Learn to Solve Algorithmic Problems & Coding Challenges](https://youtu.be/oBt53YbR9Kk?si=kKhLpcDl7AAf1oVH), [DP Series](https://www.youtube.com/watch?v=PGsgv6nXhLw&list=PLDzeHZWIZsTomOPnCiU3J95WufjE36wsb) ]