# string-transmission

Bob has received a binary string of length 𝑁 transmitted by Alice. He knows that due to errors in transmission, up to 
𝐾 bits might have been corrupted (flipped). However, he also knows that the string Alice intended to transmit was not periodic. A string is not periodic if it cannot be represented as a smaller string concatenated multiple times. For example, "0001" and "0110" are not periodic, while "00000" and "010101" are periodic.

Bob wants to determine the number of possible strings that Alice could have originally transmitted.

### Input Format :
+ The first line contains the number of test cases 𝑇.
+ For each test case:
    + The first line contains two integers 𝑁 and 𝐾:
      + 𝑁 is the length of the binary string.
      + 𝐾 is the maximum number of bits that may have been corrupted.
    + The second line contains a binary string of length 𝑁.

### Constraints :

$$ 1 \le T \le 20 $$

$$ 1 \le N \le 1000 $$ 

$$ 0 \le K \le N $$ 

### Output Format
Output 𝑇 lines, one for each test case, each containing the number of possible original strings Alice could have transmitted. Since the answers can be very large, output each number modulo 1000000007.

<table width=100%>
<tr>
<th>Sample Input :</th>
<th>Sample Output :</th>
</tr>

<tr>
<td>

```
3
5 0
00000
3 1
001
3 3
101
```
</td>

<td>

```
0
3
6
```
</td>
</tr>
</table>

## Explaination :

A string is periodic if it can be formed by repeating k strings, for some k. It is equivalent to saying that A string s is periodic if and only if there exists at least one prime p, such that it is a string a, which can be repeated p times to get s.

Let f(d) denote the number of strings s', such that s and s' differ at atmost k indices, and s' can be formed by a repeating a string d times.

Then, the required answer is:

$$ \sum_{d|n} \mu(d) f(d)$$

Now, for a given d, we have to find f(d). Break the string's indices into n/d different groups according to the remainder they leave on dividing by d. we do this because s_i = s_i + (n/d), and therefore all indices with same remainder modulo n/d have same value. So, for every such group j, we find number of zeroes(say g(i,0)) and ones( say g(i, 1)) at such indices in this part. Clearly, we either have to flip either all zeroes or all ones to make the values at all indices of these parts equal. Now, say we flip x_i indices of i'th group. Then, since maximum number of flips allowed are k,

$$ \sum_{i=1}^{n/d} x_i \le k $$

Also, x_i ∈ {g(i,0),g(i,1)}. Therefore, f(d) is the same as the sum of coefficients of all powers ≤ k in:

$$ \prod_{i=1}^{n/d} (x^{g(i, 0)} + x^{g(i, 1)}) $$

This polynomial, and hence f(d) can be evaluated using naive multiplication in O(k*(n/d)).

Now since , 

$$ \sum_{d/n} \frac{n}{d} \le \sum_{d=1}^{n} \frac{n}{d} = O(nlog(n)) $$

the overall comlexity is :

$$ O(knlog(n)) $$


## Solution :

```cpp
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int num_test_cases, length, max_corruption;
char binary_string[1024];
int dp[1024], dp2[1024][1024];
int cost[1024][2];

const int MOD = 1000000007;

void add(int& y, int x) { 
    y += x; 
    if (y >= MOD) 
        y -= MOD; 
}

void sub(int& y, int x) { 
    y -= x; 
    if (y < 0) 
        y += MOD; 
}

// Calculate the cost of flipping each bit for each section of the string
void calculate_costs(int section_size) {
    for (int i = 0; i < section_size; i++) {
        cost[i][0] = cost[i][1] = 0;
        for (int j = 0; j < length / section_size; j++) {
            if (binary_string[j * section_size + i] == '0') {
                cost[i][1]++;
            } else {
                cost[i][0]++;
            }
        }
    }
}

// Recursive function to solve the problem using dynamic programming
int solve(int section_size, int idx, int remaining_corruption) {
    if (remaining_corruption < 0) 
        return 0;
    if (idx == section_size) 
        return 1;
    
    int& result = dp2[idx][remaining_corruption];
    if (result == -1) {
        result = solve(section_size, idx + 1, remaining_corruption - cost[idx][0]);
        add(result, solve(section_size, idx + 1, remaining_corruption - cost[idx][1]));
    }
    return result;
}

int main() {
    cin >> num_test_cases;
    
    while (num_test_cases--) {
        cin >> length >> max_corruption;
        cin >> binary_string;
        
        for (int i = 1; i <= length; i++) {
            if (length % i == 0) {
                memset(dp2, -1, sizeof dp2);
                calculate_costs(i);
                dp[i] = solve(i, 0, max_corruption);
                
                // Adjust the result based on divisor
                for (int j = 1; j < i; j++) {
                    if (i % j == 0) {
                        sub(dp[i], dp[j]);
                    }
                }
            }
        }
        
        cout << dp[length] << endl;
    }
    return 0;
}
```

### Global Variables and Constants :

```cpp
int num_test_cases, length, max_corruption;
char binary_string[1024];
int dp[1024], dp2[1024][1024];
int cost[1024][2];
const int MOD = 1000000007;
```

+ `num_test_cases`: Number of test cases.
+ `length`: Length of the binary string.
+ `max_corruption`: Maximum number of bits that can be corrupted.
+ `binary_string`: Array to store the binary string.
+ `dp`: Array to store the number of valid strings for different periods.
+ `dp2`: Dynamic programming table for the recursive solution.
+ `cost`: Array to store the cost (number of flips) required to make all bits in a section the same.
+ `MOD`: Modulus value to keep results within bounds.

### Helper Functions
+ Add Function :

```cpp
void add(int& y, int x) { 
    y += x; 
    if (y >= MOD) 
        y -= MOD; 
}
```
Adds `x` to `y` and ensures the result is within the modulus `MOD`.

+ Subtract Function :

```cpp
void sub(int& y, int x) { 
    y -= x; 
    if (y < 0) 
        y += MOD; 
}
```

Subtracts `x` from `y` and ensures the result is non-negative within the modulus `MOD`.

+ Calculate Costs Function :

```cpp
void calculate_costs(int section_size) {
    for (int i = 0; i < section_size; i++) {
        cost[i][0] = cost[i][1] = 0;
        for (int j = 0; j < length / section_size; j++) {
            if (binary_string[j * section_size + i] == '0') {
                cost[i][1]++;
            } else {
                cost[i][0]++;
            }
        }
    }
}
```
+ DESC :
  + Calculates the cost of flipping each bit to either '0' or '1' for each section of size `section_size`.
  + `cost[i][0]` counts the number of '1's that need to be flipped to '0' in section i.
  + `cost[i][1]` counts the number of '0's that need to be flipped to '1' in section i.

+ Solve Function :
```cpp
int solve(int section_size, int idx, int remaining_corruption) {
    if (remaining_corruption < 0) 
        return 0;
    if (idx == section_size) 
        return 1;
    
    int& result = dp2[idx][remaining_corruption];
    if (result == -1) {
        result = solve(section_size, idx + 1, remaining_corruption - cost[idx][0]);
        add(result, solve(section_size, idx + 1, remaining_corruption - cost[idx][1]));
    }
    return result;
}
```
+ DESC :
  + Recursively solves for the number of valid strings for a given section size.
  + `section_size`: Current section size being considered.
  + `idx`: Current index in the section.
  + `remaining_corruption`: Remaining number of allowed corruptions.
  + Uses memoization (`dp2`) to store intermediate results and avoid recomputation.

+ Main Function :

```cpp
int main() {
    cin >> num_test_cases;
    
    while (num_test_cases--) {
        cin >> length >> max_corruption;
        cin >> binary_string;
        
        for (int i = 1; i <= length; i++) {
            if (length % i == 0) {
                memset(dp2, -1, sizeof dp2);
                calculate_costs(i);
                dp[i] = solve(i, 0, max_corruption);
                
                // Adjust the result based on divisor
                for (int j = 1; j < i; j++) {
                    if (i % j == 0) {
                        sub(dp[i], dp[j]);
                    }
                }
            }
        }
        
        cout << dp[length] << endl;
    }
    return 0;
}
```

+ DESC:
  + Reads the number of test cases.
  + For each test case:
  + Reads the length of the binary string and the maximum number of allowed corruptions.
  + Reads the binary string.
  + For each possible section size `i` that divides the length:
    + Initializes `dp2` to `-1` to reset the memoization table.
    + Calculates the costs for the current section size `i`.
    + Solves for the number of valid strings for the current section size using the solve function.
    + Adjusts the result to ensure only non-periodic strings are counted by subtracting results of smaller divisors.
  + Outputs the result for the current test case.

+ Explanation :

  + The program aims to count the number of valid non-periodic binary strings that could have been sent by Alice.
  + For each possible period `i`, it calculates the cost to make the string periodic with that period.
  + It uses dynamic programming to efficiently count the valid strings with up to `k` corruptions.
  + The solution involves recursion with memoization to avoid redundant calculations.
  + Finally, it ensures the result is within the specified modulus `MOD` and outputs it for each test case.