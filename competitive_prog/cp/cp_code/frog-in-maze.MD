# frog-in-maze

Alef the Frog is in an n * m two-dimensional maze represented as a table. The maze has the following characteristics:

+ Each cell can be free or can contain an obstacle, an exit, or a mine.
+ Any two cells in the table considered adjacent if they share a side.
+ The maze is surrounded by a solid wall made of obstacles.
+ Some pairs of free cells are connected by a bidirectional tunnel.


<img src="img/frog.png" width=100%>

When Alef is in any cell, he can randomly and with equal probability choose to move into one of the adjacent cells that don't contain an obstacle in it. If this cell contains a mine, the mine explodes and Alef dies. If this cell contains an exit, then Alef escapes the maze.

When Alef lands on a cell with an entrance to a tunnel, he is immediately transported through the tunnel and is thrown into the cell at the other end of the tunnel. Thereafter, he won't fall again, and will now randomly move to one of the adjacent cells again. (He could possibly fall in the same tunnel later.)

It's possible for Alef to get stuck in the maze in the case when the cell in which he was thrown into from a tunnel is surrounded by obstacles on all sides.

Your task is to write a program which calculates and prints a probability that Alef escapes the maze.

`Input Format` :

The first line contains three space-separated integers n, m and k denoting the dimensions of the maze and the number of bidirectional tunnels.

The next n lines describe the maze. The i'th line contains a string of length m denoting the i'th row of the maze. The meaning of each character is as follows:

+ \# denotes an obstacle.
+ A denotes a free cell where Alef is initially in.
+ \* denotes a cell with a mine.
+ % denotes a cell with an exit.
+ O denotes a free cell (which may contain an entrance to a tunnel).

The next k lines describe the tunnels. The 'th line contains four space-separated integers i_1, j_1, i_2, j_2. Here, (i_1, j_1) and (i_2, j_2)  denote the coordinates of both entrances of the tunnel. (i, j) denotes the row and column number, respectively.

`Constraints` :

+ 1 ≤ n, m ≤ 20
+ 0 ≤ 2+k ≤ n+m
+ 1 ≤ i_1, i_2 ≤ n
+ 1 ≤ j_1, j_2 ≤ m
+ (i_1, j_1) and (i_2, j_2) are distinct
+ A appears exactly once.
+ Each free cell contains at most one entrance to a tunnel.
+ If a cell contains an entrance to a tunnel, then it doesn't contain an obstacle, mine or exit, and Alef doesn't initially stand in it.
+ Tunnels don't connect adjacent cells.

`Output Format` :

Print one real number denoting the probability that Alef escapes the maze. Your answer will be considered to be correct if its (absolute) difference from the true answer is not greater than 10^{-6}.


<table width=100%>
<tr>
<th>Sample Input 0:</th>
<th>Sample Output 0:</th>
</tr>

<tr>
<td>

```
3 6 1
###*OO
O#OA%O
###*OO
2 3 2 1
```
</td>

<td>

```
0.25
```
</td>
</tr>
</table>

Explanation 0 :

The following depicts this sample case:

<img src="img/frog2.png" width=100%>

In this case, Alef will randomly choose one of four adjacent cells. If he goes up or down, he will explode and die. If he goes right, he will escape. If he goes left, he will go through a tunnel and get stuck in cell (2, 1). So the probability of Alef escaping is 1/4.