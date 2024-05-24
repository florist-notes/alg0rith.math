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