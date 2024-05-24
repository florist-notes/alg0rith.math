# yet-another-minimax-problem

You are given n non-negative integers, a_0, a_1, ..., a_{n-1}. We define the score for some permutation (p) of length n to be the maximum of a_p_{i} ⊕ a_p_{i+1} for 0 ≤ i ≤ n-1.

Find the permutation with the minimum possible score and print its score.

Note: ⊕ is the exclusive-OR (XOR) operator.

`Input Format` :

The first line contains single integer, n, denoting the number of integers.
The second line contains n space-separated integers, a_0, a_1, ..., a_{n-1}, describing the respective integers.

`Constraints` :

$$ 2 \le n \le 3000 $$
$$ 0 \le a_i \le 10^9 $$

`Output Format` :

Print a single integer denoting the minimum possible score.


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
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
5
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
3
1 2 3
```
</td>

<td>

```
2
```
</td>
</tr>
</table>

`Explanation` :

+ Sample Case 0:
The permutation with the minimum score is (3, 2, 1, 4):

$$ a_0 ⊕ a_1 = 3 ⊕ 2 = 1 $$
$$ a_1 ⊕ a_2 = 2 ⊕ 1 = 3 $$
$$ a_2 ⊕ a_3 = 1 ⊕ 4 = 5 $$

Because the permutation's score is the maximum of these values, we print  on a new line.

+ Sample Case 1:
The permutation with the minimum score is (1, 3, 2):

$$ a_0 ⊕ a_1 = 1 ⊕ 3 = 2 $$
$$ a_1 ⊕ a_2 = 3 ⊕ 2 = 1 $$

Because the permutation's score is the maximum of these values, we print 2 on a new line.


## Explanation:

If all a_i are equal, the answer is 0. Otherwise, let b be the highest bit such that there are two numbers which differ in b.


Let's find a pair of numbers, a_i and a_j, which differ in b (their highest bit) with minimum(a_i ⊕ a_j) - s. In every permutation of a_i, the answer will be not be < s as there will be two consecutive numbers which differ in b. If all a_i with 0 in b are placed before all a_i with 1 in b, the maximum XOR will be between these two groups (and, in some rearrangements, it will be exactly s). These statements prove that the answer to the problem is s.


How can we quickly find a pair of numbers from two groups with a minimum xor?
Let's cut off all bits ≥ b, as the answer doesn't depend on them. Then, put all numbers from the first group into the binary tree (from higher to lower bits, on the i-th stage if (b-i-1)th bit is 0, go to the left subtree; otherwise, go to the right subtree). The best pair for each number from the second group can then be found in O(b) time.


The overall complexity of the solution is O(nlogC), where C is the maximum a_i.


```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int num_integers;
    cin >> num_integers;

    vector<long long> integers(num_integers);
    for (int i = 0; i < num_integers; i++)
        cin >> integers[i];

    long long min_xor = 0;
    for (int bit_position = 30; bit_position >= 0; bit_position--) {
        vector<int> counts(2);
        for (int j = 0; j < num_integers; j++) {
            counts[integers[j] >> bit_position & 1]++;
        }

        if (counts[0] == num_integers || counts[1] == num_integers) continue;

        vector<long long> high_bit, low_bit;
        for (int j = 0; j < num_integers; j++) {
            if (integers[j] >> bit_position & 1) {
                high_bit.push_back(integers[j]);
            } else {
                low_bit.push_back(integers[j]);
            }
        }

        long long min_xor_value = LLONG_MAX;
        for (long long x : high_bit) {
            for (long long y : low_bit) {
                min_xor_value = min(min_xor_value, x ^ y);
            }
        }
        min_xor = min_xor_value;
        break;
    }

    cout << min_xor << endl;

    return 0;
}
```

### `Explanation`:

+ We start by inputting the number of integers `num_integers`.

+ We then input `num_integers` integers into a vector called `integers`.

+ We initialize the variable `min_xor` to store the final answer, which represents the minimum XOR value.

+ We iterate through each bit position from the 30th bit down to the 0th bit using a variable called `bit_position`.

+ Within each iteration, we count the number of 0s and 1s at the current bit position using a vector called `counts`.

+ If all numbers have the same bit value at the current position, we skip to the next position using the `continue` statement.

+ Otherwise, we separate the numbers into two vectors `high_bit` and `low_bit` based on their bit values at the current position.

+ We then find the minimum XOR value between pairs of numbers from `high_bit` and `low_bit` using a variable called `min_xor_value`.

+ We update the `min_xor` variable with the minimum XOR value found for the current bit position.

+ Finally, we output the final minimum XOR value stored in `min_xor`.