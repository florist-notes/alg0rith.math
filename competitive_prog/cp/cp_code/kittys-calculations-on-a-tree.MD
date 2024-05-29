# kittys-calculations-on-a-tree

Kitty has a tree, T, consisting of n nodes where each node is uniquely labeled from 1 to n. Her friend Alex gave her q sets, where each set contains k distinct nodes. Kitty needs to calculate the following expression on each set:

$$ ( \sum_{{u, v}} u.v. dist(u, v)) *  mod (10^9 + 7) $$

where:
+ {u, v} denotes an unordered pair of nodes belonging to the set.
+ dist(u, v) denotes the number of edges on the unique (shortest) path between nodes u and v.

Given T and q sets of k distinct nodes, calculate the expression for each set. For each set of nodes, print the value of the expression modulo 10^9 +7 on a new line.

Example :

edges = [[1, 2], [1, 3], [1, 4], [3, 5], [3, 6], [3, 7]]

queries = [4, 5, 7]

The graph looks like this:

<img src="img/kitty.png" width=100%> 

There are three pairs that can be created from the query set: [4, 5], [4, 7], [5, 7]. The distance from 4 to 5 is 3, from 4 to 7 is 3, and from 5 to 7 is 2.

Now do the summation:

$$

(4 \cdot 5 \cdot \text{dist}(4, 5) + 4 \cdot 7 \cdot \text{dist}(4, 7) + 5 \cdot 7 \cdot \text{dist}(5, 7)) \mod (10^9 + 7) \Rightarrow \\ (4 \cdot 5 \cdot 3 + 4 \cdot 7 \cdot 3 + 5 \cdot 7 \cdot 2) \mod (10^9 + 7) \Rightarrow 214

$$


Input Format :
The first line contains two space-separated integers, the respective values of n (the number of nodes in tree T) and q (the number of nodes in the query set).
Each of the n - 1 subsequent lines contains two space-separated integers, a and b, that describe an undirected edge between nodes a and b.
The 2.q subsequent lines define each set over two lines in the following format:
1. The first line contains an integer, k, the size of the set.
2. The second line contains k space-separated integers, the set's elements.

### Constraints

$$ 1 \le n \le 2.10^5 $$
$$ 1 \le a,b \le n $$
$$ 1 \le q \le 10^5 $$
$$ 1 \le k \le 10^5 $$

$$ The \ sum \  of \  k_i \  over  \ all \  q \  does \  not \  exceed  \ 2 * 10⁵. $$
$$ All \ elements \ in \ each \ set \ are \ distinct. $$

### Subtasks
+ 1 < n < 2000 for 24% of the maximum score.
+ 1 ≤ n ≤ 5.10^4 for 45% of the maximum score.
+ 1 ≤ n ≤ 2.10^5 for 100% of the maximum score.

### Output Format
Print q lines of output where each line i contains the expression for the ith query, modulo 10^9 + 7.


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
7 3
1 2
1 3
1 4
3 5
3 6
3 7
2
2 4
1
5
3
2 4 5
```
</td>

<td>

```
16
0
106
```
</td>
</tr>

</table>

#### Explanation 0

Tree T looks like this:

<img src="img/kitty2.png" width=100%>

We perform the following calculations for q=3 sets:

• `Set 0`: Given set {2, 4}, the only pair we can form is (u, v) = (2, 4), where dist(2, 4) = 2. We then calculate the following answer and print it on a new line:

$$
(2 \cdot 4 \cdot \text{dist}(2, 4)) \mod (10^9 + 7) \Rightarrow (2 \cdot 4 \cdot 2) \mod (10^9 + 7) \Rightarrow 16
$$


• `Set 1`: Given set {5}, we cannot form any pairs because we don't have at least two elements. Thus, we print 0 on a new line.

• `Set 2`: Given set {2, 4, 5}, we can form the pairs (2, 4), (2, 5), and (4,5). We then calculate the following answer and print it on a new line:

$$
(2 \cdot 4 \cdot \text{dist}(2, 4) + 2 \cdot 5 \cdot \text{dist}(2, 5) + 4 \cdot 5 \cdot \text{dist}(4, 5)) \mod (10^9 + 7) \Rightarrow \\ (2 \cdot 4 \cdot 2 + 2 \cdot 5 \cdot 3 + 4 \cdot 5 \cdot 3) \mod (10^9 + 7) \Rightarrow 106
$$
