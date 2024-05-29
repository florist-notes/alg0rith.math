# manipulative-numbers

Suppose that A is a list of n numbers {A_1, A_2, A_3,, A_n} and B = {B_1, B_2, B_3,..., B_n} is a permutation of these numbers, we say B is K-Manipulative if and only if:

M(B) = minimum(B_1 ⊕ B_2, B_2 ⊕ B_3, B_3 ⊕ B_4, ..., B_{n-1} ⊕ B_n, B_n ⊕ B_1) is not less than 2^k, where represents the XOR operator.
You are given A. Find the largest K such that there exists a K-manipulative permutation B.

Input:
The first line is an integer N. The second line contains N space separated integers - A_1 A_2 ... A_n.

Output:
The largest possible K, or -1 if there is no solution.

Constraints:
$$ 1 < n <= 100 $$
$$ 0 \le A_i \le 10⁹, where \ i ∈ [1, n] $$


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
3
13 3 10
```
</td>

<td>

```
2
```
</td>
</tr>

<tr>
<th>Sample Input 1:</th>
<th>Sample Output 1:</th>
</tr>

<tr>
<td>

```
4
1 2 3 4
```
</td>

<td>

```
1
```
</td>
</tr>
</table>

+ `Explanation 0` :

Here the list A is {13, 3, 10}. One possible permutation B = {10,3, 13}. Here M(B) = minimum{B1 ⊕ B2, B2 ⊕ B3, B3 ⊕ B_1} = minimum{10 ⊕ 3,3 ⊕ 13, 13 ⊕ 10} = minimum{9, 14, 7} = 7.

So there exists a permutation B of A such that M(B) is not less than 4 = 2^2. However there does not exist any permutation B of A such that M(B) is not less than 8 = 2^3. So the maximum possible value of K is 2.

+ `Explanation 1` :

Here the list A is {1, 2, 3, 4}. One possible permutation B = {1, 2, 4, 3}. Here M(B) = minimum{B_1 ⊕ B_2, B_2 ⊕ B_3, B_3 ⊕ B_4, B_4 ⊕ B_1} = minimum{1⊕2,2⊕4,4⊕3, 3⊕1} = minimum{3,6,7,2} = 2.

So there exists a permutation B of A such that M(B) is not less than 2 = 2^1. However there does not exist any permutation B of A
such that M(B) is not less than 4 = 2^2. So the maximum possible value of K is 1.

## Solution :

```cpp
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAX_N = 101;
int elements[MAX_N];
int num_elements;

// Function to check if there exists a permutation with M(B) >= 2^k
bool isKManipulative(int k) {
    map<int, int> countMap;
    int mask = 0;

    // Create a mask to consider only the top k bits
    for (int i = 30; i >= k; i--) {
        mask |= (1 << i);
    }

    // Count occurrences of masked elements
    for (int i = 0; i < num_elements; i++) {
        countMap[elements[i] & mask]++;
    }

    vector<int> counts;
    for (const auto& pair : countMap) {
        counts.push_back(pair.second);
    }

    // Sort counts to check the condition for being k-manipulative
    sort(counts.begin(), counts.end());
    if (counts.size() == 1) return false;

    int cumulative_sum = counts[0];
    for (size_t i = 1; i < counts.size(); i++) {
        if (cumulative_sum < counts[i]) return false;
        cumulative_sum += counts[i];
    }

    return true;
}

int main() {
    // Read input
    cin >> num_elements;
    for (int i = 0; i < num_elements; i++) {
        cin >> elements[i];
    }

    // Find the largest k for which there exists a k-manipulative permutation
    for (int k = 30; k >= 0; k--) {
        if (isKManipulative(k)) {
            cout << k << endl;
            return 0;
        }
    }

    // If no valid k found, output -1 (though by constraints, we should always find a valid k)
    cout << -1 << endl;
    return 0;
}
```

