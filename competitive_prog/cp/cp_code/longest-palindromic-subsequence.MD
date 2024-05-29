# longest-palindromic-subsequence

Steve loves playing with palindromes. He has a string, s, consisting of n lowercase English alphabetic characters (i.e., a through z). He wants to calculate the number of ways to insert exactly 1 lowercase character into string s such that the length of the longest palindromic subsequence of s increases by at least k. Two ways are considered to be different if either of the following conditions are satisfied:

+ The positions of insertion are different.
+ The inserted characters are different.

This means there are at most 26 x (n+1) different ways to insert exactly 1 character into a string of length n.

Given q queries consisting of n, k, and s, print the number of different ways of inserting exactly 1 new lowercase letter into string s such that the length of the longest palindromic subsequence of s increases by at least k.

`Input Format` :

The first line contains a single integer, q, denoting the number of queries. The 2q subsequent lines describe each query over two lines:

+ The first line of a query contains two space-separated integers denoting the respective values of n and k.
+ The second line contains a single string denoting s.

`Constraints` :

$$ 1 \le q \le 10 $$
$$ 1 \le n \le 1000 $$
$$ 0 \le k \le 50 $$

It is guaranteed that s consists of lowercase English alphabetic letters (i.e., a to z) only.

`Subtasks` :

+ 1 ≤ n ≤ 100 for 25% of the maximum score.
+ 1 ≤ n ≤ 1000 for 70% of the maximum score.

`Output Format` :

On a new line for each query, print the number of ways to insert exactly 1 new lowercase letter into string s such that the length of the longest palindromic subsequence of s increases by at least k.


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
3
1 1
a
3 2
aab
3 0
aba
```
</td>

<td>

```
2
1
104
```
</td>
</tr>

</table>

`Explanation` :

We perform the following q=2 queries:

1. The length of the longest palindromic subsequence of s = a is 1. There are two ways to increase this string's length by at least k = 1:

    + Insert an a at the start of string s, making it aa.
    + Insert an a at the end of string s, making it aa.

    Both methods result in aa, which has a longest palindromic subsequence of length 2 (which is longer than the original longest palindromic subsequence's length by k=1). Because there are two such ways, we print 2 on a new line.

2. The length of the longest palindromic subsequence of  s = aab is 2. There is one way to increase the length by at least k=2:

   + Insert a b at the start of string s, making it baab.

    We only have one possible string, baab, and the length of its longest palindromic subsequence is 4 (which is longer than the original longest palindromic subsequence's length by k=2). Because there is one such way, we print 1 on a new line. 


### Solution :


```cpp
#include <bits/stdc++.h>
using namespace std;

const int MAX_LEN = 3005;

// Global variables for dynamic programming and memoization
int n, dp[MAX_LEN][MAX_LEN], used[MAX_LEN][MAX_LEN], lcsBetween[MAX_LEN][MAX_LEN];
string str;

// Function to compute the Longest Palindromic Subsequence (LPS) length
int computeLPS(int left = 0, int right = n - 1) {
    if (left > right) return 0;
    if (used[left][right]) return dp[left][right];
    used[left][right] = 1;
    if (left == right) return dp[left][right] = 1;
    dp[left][right] = max(computeLPS(left + 1, right), computeLPS(left, right - 1));
    if (str[left] == str[right])
        dp[left][right] = max(dp[left][right], 2 + computeLPS(left + 1, right - 1));
    return dp[left][right];
}

int main() {
    int queryCount, minIncrease;
    cin >> queryCount;
    while (queryCount--) {
        cin >> n >> minIncrease;
        cin >> str;

        // Handle edge cases directly
        if (minIncrease == 0) {
            cout << (n + 1) * 26 << endl;
            continue;
        }
        if (minIncrease > 2) {
            cout << 0 << endl;
            continue;
        }

        // Reset memoization and dynamic programming arrays
        memset(used, 0, sizeof used);
        memset(dp, 0, sizeof dp);
        memset(lcsBetween, 0, sizeof lcsBetween);

        // Precompute the LCS for substrings of `str`
        for (int left = 0; left < n; ++left) {
            for (int right = n - 1; right > left; --right) {
                if (left > 0) lcsBetween[left][right] = max(lcsBetween[left][right], lcsBetween[left - 1][right]);
                if (right + 1 < n) lcsBetween[left][right] = max(lcsBetween[left][right], lcsBetween[left][right + 1]);
                if (str[left] == str[right]) {
                    int curLCS = 2;
                    if (left > 0 && right + 1 < n) curLCS += lcsBetween[left - 1][right + 1];
                    lcsBetween[left][right] = max(lcsBetween[left][right], curLCS);
                }
            }
        }

        // Compute the LPS of the original string
        int originalLPS = computeLPS();
        int insertionWays = 0;

        // Try inserting each character from 'a' to 'z' at each position
        for (int insertPos = 0; insertPos <= n; ++insertPos) {
            for (char ch = 'a'; ch <= 'z'; ++ch) {
                int maxLPSAfterInsertion = 0;

                // Check potential LPS increases by inserting `ch` at `insertPos`
                if (insertPos > 0 && insertPos < n)
                    maxLPSAfterInsertion = max(maxLPSAfterInsertion, lcsBetween[insertPos - 1][insertPos] + 1);

                // Check the left part of the string
                for (int j = 0; j < insertPos; ++j) {
                    if (ch == str[j]) {
                        int curLPS = 2;
                        if (insertPos > 0) curLPS += dp[j + 1][insertPos - 1];
                        if (j > 0) curLPS += lcsBetween[j - 1][insertPos];
                        maxLPSAfterInsertion = max(maxLPSAfterInsertion, curLPS);
                    }
                }

                // Check the right part of the string
                for (int j = insertPos; j < n; ++j) {
                    if (ch == str[j]) {
                        int curLPS = 2 + dp[insertPos][j - 1];
                        if (insertPos > 0) curLPS += lcsBetween[insertPos - 1][j + 1];
                        maxLPSAfterInsertion = max(maxLPSAfterInsertion, curLPS);
                    }
                }

                // Check if the new LPS meets the required increase
                if (maxLPSAfterInsertion - originalLPS >= minIncrease) insertionWays++;
            }
        }
        cout << insertionWays << endl;
    }
    return 0;
}
```