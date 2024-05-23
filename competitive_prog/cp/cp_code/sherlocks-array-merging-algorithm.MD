# sherlocks-array-merging-algorithm


Watson gave Sherlock a collection of arrays V. Here each V_i is an array of variable length. It is guaranteed that if you merge the arrays into one single array, you'll get an array, M, of n distinct integers in the range [1, n].

Watson asks Sherlock to merge V into a sorted array. Sherlock is new to coding, but he accepts the challenge and writes the following algorithm:

+ M ← [] (an empty array).
+ k ← number of arrays in the collection V.
+ While there is at least one non-empty array in V:
    + T ← [] (an empty array) and i ← 1.
    + While i ≤ k :
        + If V_i is not empty:
          + Remove the first element of V_i and push it to T.
        + i ← i + 1.
    + While T is not empty:
        + Remove the minimum element of T and push it to M.     
+ Return T as the output.
  
Let's see an example. Let V be { [3,5], [1], [2,4] }. The image below demonstrates how Sherlock will do the merging according to the algorithm:

<img src="img/sherlock_1.png" width=45%> <img src="img/sherlock_2.png" width=45%>

Sherlock isn't sure if his algorithm is correct or not. He ran Watson's input, V, through his pseudocode algorithm to produce an output, M, that contains an array of n integers. However, Watson forgot the contents of V and only has Sherlock's M with him! Can you help Watson reverse-engineer M to get the original contents of V?

Given m, find the number of different ways to create collection V such that it produces m when given to Sherlock's algorithm as input. As this number can be quite large, print it modulo 10^9+7.

`Notes`:

+ Two collections of arrays are different if one of the following is true:

    + Their sizes are different.
    + Their sizes are the same but at least one array is present in one collection but not in the other.

+ Two arrays, A and B, are different if one of the following is true:

    + Their sizes are different.
    + Their sizes are the same, but there exists an index i such that a_i ≠ b_i. 

`Input Format` :

The first line contains an integer, n, denoting the size of array M.
The second line contains n space-separated integers describing the respective values of m_0, m_1, ..., m_{n-1}.

`Constraints` :

$$ 1 \le n \le 1200 $$

$$ 1 \le m_i \le n $$

`Output Format` :

Print the number of different ways to create collection V, modulo 10^9 + 7.

<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
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
4
```
</td>
</tr>
</table>

Explanation 0 :

There are four distinct possible collections:
+ 1. V = {[1,2,3]} 
+ 2. V = {[1], [2], [3]}
+ 3. V = {[1,3], [2]}
+ 4. v = {[1], [2,3]}

Thus, we print the result of 4 mod (10^9+7) = 4 as our answer.


<table width=100%>
<tr>
<th>Sample Input 1:</th>
<th>Sample Output 1:</th>
</tr>

<tr>
<td>

```
2
2 1
```
</td>

<td>

```
1
```
</td>
</tr>
</table>

Explanation 1 :

The only distinct possible collection is V = {[2, 1]}, so we print the result of 1mod(10^9+7) = 1 as our answer.