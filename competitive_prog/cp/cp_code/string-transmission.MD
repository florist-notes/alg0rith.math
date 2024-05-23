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

## Solution :
