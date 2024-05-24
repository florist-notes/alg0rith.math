#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 1205;
const int MOD = 1e9 + 7;

int n;
int m[MAX_N]; // Input array M
int right_bound[MAX_N]; // Right boundaries of increasing sequences

int factorial[MAX_N]; // Factorial array
int inverse_factorial[MAX_N]; // Inverse factorial array

int dp[MAX_N][MAX_N]; // Dynamic programming array

// Recursive function to compute the number of ways to create collection V
int countWays(int last, int pos) {
    // Base case: if we reached the end of array M, return the inverse of last
    if (pos > n) return inverse_factorial[last];

    // If the value is already computed, return it
    if (dp[last][pos] != -1) return dp[last][pos];

    long long res = 0;
    // Iterate over the possible next positions to split the array
    for (int i = pos; i <= min(right_bound[pos], last + pos - 1); ++i) {
        // Compute the number of ways recursively and update the result
        res += (((1LL * factorial[i - pos + 1] * countWays(i - pos + 1, i + 1)) % MOD) * inverse_factorial[last - (i - pos + 1)]) % MOD;
    }
    // Store the result in dp array and return it
    return dp[last][pos] = res % MOD;
}

int main() {
    cin >> n;
    // Input array M
    for (int i = 1; i <= n; ++i) {
        cin >> m[i];
    }
    // Calculate right boundaries of increasing sequences
    right_bound[n] = n;
    for (int i = n - 1; i >= 1; --i) {
        if (m[i + 1] > m[i]) right_bound[i] = right_bound[i + 1];
        else right_bound[i] = i;
    }
    // Precompute factorial array
    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
    }
    // Precompute inverse factorial array using modulo inverse
    inverse_factorial[0] = 1;
    inverse_factorial[1] = 1;
    for (int i = 2; i <= n; ++i) {
        inverse_factorial[i] = ((-1LL * (MOD / i) * inverse_factorial[MOD % i]) % MOD + MOD) % MOD;
    }
    for (int i = 2; i <= n; ++i) {
        inverse_factorial[i] = (1LL * inverse_factorial[i - 1] * inverse_factorial[i]) % MOD;
    }
    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    int ans = 0;
    // Compute the answer
    for (int i = 1; i <= right_bound[1]; ++i) {
        ans += (1LL * factorial[i] * countWays(i, i + 1)) % MOD;
        if (ans >= MOD) ans -= MOD;
    }
    cout << ans << endl; // Output the answer
    return 0;
}
