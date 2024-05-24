# dynamic-programming-classics-the-longest-common-subsequence

A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements. Longest common subsequence (LCS) of 2 sequences is a subsequence, with maximal length, which is common to both the sequences.

Given two sequences of integers, A = [a[1], a[2],..., a[n]] and B = [b[1], b[2],..., b[n]], find the longest common subsequence and print it as a line of space-separated integers. If there are multiple common subsequences with the same maximum length, print any one of them.

In case multiple solutions exist, print any of them. It is guaranteed that at least one non-empty common subsequence will exist.

Recommended References

This Youtube video tutorial explains the problem and its solution quite well.

### Function Description :

Complete the longestCommonSubsequence function in the editor below. It should return an integer array of a longest common subsequence.

longestCommonSubsequence has the following parameter(s):

+ a: an array of integers
+ b: an array of integers

### Input Format :

+ The first line contains two space separated integers n and m, the sizes of sequences A and B.
+ The next line contains n space-separated integers A[i].
+ The next line contains m space-separated integers B[j].

### Constraints :

$$ 1 \le n \le 100 $$
$$ 1 \le m \le 100 $$
$$ 0 \le a[i] \le 1000, where i ∈ [1, n] $$
$$ 0 \le b[j] \le 1000, where j ∈ [1, m] $$

### Constraints :

$$ 1 \le n,m \le 100 $$
$$ 0 \le a[i], b[j] \le 1000 $$

### Output Format :

Print the longest common subsequence as a series of space-separated integers on one line. In case of multiple valid answers, print any one of them.


<table width=100%>
<tr>
<th>Sample Input :</th>
<th>Sample Output :</th>
</tr>

<tr>
<td>

```
5 6
1 2 3 4 1
3 4 1 2 1 3
```
</td>

<td>

```
1 2 3
```
</td>
</tr>
</table>

+ Explanation :

There is no common subsequence with length larger than 3. And "1 2 3", "1 2 1", "3 4 1" are all correct answers.


```cpp
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> longestCommonSubsequence(const std::vector<int>& a, const std::vector<int>& b) {
    int n = a.size();
    int m = b.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::vector<int> result;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> b[i];
    }

    std::vector<int> result = longestCommonSubsequence(a, b);

    for (int i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
```

### Libraries Used:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
```

+ `<iostream>`: Standard input-output library in C++.
+ `<vector>`: Used for dynamic arrays.
+ `<algorithm>`: Provides various algorithms like `max()` and `reverse()`.

### Function Definition:

```cpp
std::vector<int> longestCommonSubsequence(const std::vector<int>& a, const std::vector<int>& b) {
    // Function body
}
```

+ `longestCommonSubsequence`: This function takes two vectors `a` and `b` as input and returns a vector representing the longest common subsequence.

### Dynamic Programming Table Initialization:

```cpp
    int n = a.size();
    int m = b.size();

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
```

+ `n` and `m` are the sizes of vectors `a` and `b` respectively.
+ `dp` is a 2D vector representing the dynamic programming table. It has `n+1` rows and `m+1` columns, initialized with zeros.

### Dynamic Programming to Compute LCS Length:

```cpp
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
```

+ This nested loop iterates over each element of `dp`.
+ If the corresponding elements in `a` and `b` are equal, we increment the LCS length by 1.
+ If not, we take the maximum LCS length obtained so far from either the previous row or the previous column.

### Reconstructing LCS:

```cpp
    std::vector<int> result;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            result.push_back(a[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    std::reverse(result.begin(), result.end());
    return result;
```

+ We start from the bottom-right corner of the dynamic programming table and trace back to reconstruct the LCS.
+ If the current elements in `a` and `b` are equal, we add it to the `result` vector and move diagonally upwards.
+ If not, we move either upwards or leftwards depending on which cell has a greater LCS length.
+ Finally, we reverse the `result` vector to obtain the LCS in correct order and return it.

### Main Function:

```cpp
int main() {
    // Input reading
    // Function call to compute LCS
    // Output printing
}
```

+ Reads input sequences `a` and `b`.
+ Calls the `longestCommonSubsequence` function to compute the LCS.
+ Prints the resulting LCS.

This code efficiently computes the longest common subsequence of two sequences using dynamic programming and demonstrates the power of the C++ Standard Template Library (STL).