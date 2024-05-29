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
