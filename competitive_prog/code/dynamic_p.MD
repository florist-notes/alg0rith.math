# Dynamic Programming

 Dynamic Programming (DP) is a powerful technique for solving optimization problems by breaking them down into simpler subproblems and storing the solutions to these subproblems to avoid redundant computations. It is particularly useful for problems with overlapping subproblems and optimal substructure.

 ### Key Concepts of Dynamic Programming :
+ `Overlapping Subproblems`: The problem can be broken down into subproblems which are reused multiple times.
+ `Optimal Substructure`: The optimal solution of the problem can be constructed from optimal solutions of its subproblems.
+ `Memoization (Top-Down)`: Recursively solve subproblems and store their results.
+ `Tabulation (Bottom-Up)`: Iteratively solve subproblems and build up the solution in a table.

### Example Problems and Solutions :

`Fibonacci Sequence` : The Fibonacci sequence is a classic example of a DP problem. The  𝑛-th Fibonacci number is defined as:

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
    cout << "Fibonacci("<< n <<") = "<< fib(n) <<endl;
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
    cout << "Fibonacci("<< n <<") = "<< fib(n) <<endl;
    return 0;
}
```
</td>
</tr>
</table>

`0/1 Knapsack Problem` : Given weights and values of 𝑛 items, put these items in a knapsack of capacity 𝑊 to get the maximum total value in the knapsack.

DP Solution with Tabulation:
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

Resources : [ Video : [5 Simple Steps for Solving Dynamic Programming Problems](https://youtu.be/aPQY__2H3tE?si=5E-UJDxwCPKKrxC7) ]