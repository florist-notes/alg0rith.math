# castle-on-the-grid

You are given a square grid with some cells open (.) and some blocked (X). Your playing piece can move along any row or column until it reaches the edge of the grid or a blocked cell. Given a grid, a start and a goal, determine the minmum number of moves to get to the goal.

`Example` :

+ grid() = ['...','.X.','...']
+ startX = 0
+ startY = 0
+ goalX = 1
+ goalY = 2

The grid is shown below:

```
...
.X.
...
```

The starting position (startX, startY) = (0,0) so start in the top left corner. The goal is (goalX, goalY) = (1, 2). The path is (0, 0) → (0, 2) → (1, 2). It takes  moves to reach the goal.

`Function Description` :

Complete the minimumMoves function in the editor.

minimumMoves has the following parameter(s):

string grid[n]: an array of strings that represent the rows of the grid
+ int startX: starting X coordinate
+ int startY: starting Y coordinate
+ int goalX: ending X coordinate
+ int goalY: ending Y coordinate

`Returns` :

+ int: the minimum moves to reach the goal

`Input Format` :

The first line contains an integer n, the size of the array grid.
Each of the next n lines contains a string of length n.
The last line contains four space-separated integers, startX, startY, goalX, goalY

`Constraints` :

$$ 1 \le n \le 100 $$

$$ 0 \le startX, startY, goalX, goalY < n $$


<table width=100%>
<tr>
<th>Sample Input :</th>
<th>Sample Output :</th>
</tr>

<tr>
<td>

```
STDIN       FUNCTION
-----       --------
3           grid[] size n = 3
.X.         grid = ['.X.','.X.', '...']
.X.
...
0 0 0 2     startX = 0, startY = 0, goalX = 0, goalY = 2
```
</td>

<td>

```
3
```
</td>
</tr>
</table>

`Explanation`:

Here is a path that one could follow in order to reach the destination in 3 steps:

(0, 0) → (2, 0) → (2, 2) → (0, 2)


```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <climits>

using namespace std;

int minimumMoves(vector<string>& grid, int startX, int startY, int goalX, int goalY) {
    int n = grid.size();
    vector<vector<int>> moves(n, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;

    q.push({startX, startY});
    moves[startX][startY] = 0;

    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        for (auto& dir : directions) {
            int dx = dir.first;
            int dy = dir.second;

            int newX = x + dx;
            int newY = y + dy;
            
            // Check if the new position is within the grid and not blocked
            while (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] != 'X') {
                // If the move is shorter than the recorded one, update it
                if (moves[newX][newY] > moves[x][y] + 1) {
                    moves[newX][newY] = moves[x][y] + 1;
                    q.push({newX, newY});
                }
                newX += dx;
                newY += dy;
            }
        }
    }

    return moves[goalX][goalY];
}

int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY);
    cout << result << endl;
    return 0;
}
```

### Library Inclusions: 

```cpp
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <climits>
```

These lines include necessary C++ standard libraries such as `iostream` for input/output, `queue` for BFS implementation, `vector` for dynamic arrays, `string` for handling strings, `utility` for `pair` usage, and `climits` for using `INT_MAX` constant.

### Function Definition:

```cpp
int minimumMoves(vector<string>& grid, int startX, int startY, int goalX, int goalY) {
```

This function `minimumMoves` takes the grid, starting coordinates (`startX`, `startY`), and goal coordinates (`goalX`, `goalY`) as input parameters and returns an integer representing the minimum number of moves required to reach the goal.

### Initialization:

```cpp
int n = grid.size();
vector<vector<int>> moves(n, vector<int>(n, INT_MAX));
queue<pair<int, int>> q;
```

`n` is initialized with the size of the grid. A 2D vector `moves` of size `n x n` is created to store the minimum moves required to reach each position. `INT_MAX` is used to initialize all values in `moves` to represent that no moves have been made yet. A queue `q` of pairs of integers (representing positions) is created to perform BFS.

### Starting Position Initialization:

```cpp
q.push({startX, startY});
moves[startX][startY] = 0;
```

The starting position `(startX, startY)` is pushed onto the queue `q`, and the number of moves required to reach this position is set to `0` in the `moves` array.

### Direction Definitions:

```cpp
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
```
This vector defines the four possible directions (up, down, left, right) that can be explored from a given position.

### Breadth-First Search (BFS):

```cpp
while (!q.empty()) {
    auto current = q.front();
    q.pop();

    int x = current.first;
    int y = current.second;

    for (auto& dir : directions) {
        int dx = dir.first;
        int dy = dir.second;

        int newX = x + dx;
        int newY = y + dy;
        
        // Check if the new position is within the grid and not blocked
        while (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] != 'X') {
            // If the move is shorter than the recorded one, update it
            if (moves[newX][newY] > moves[x][y] + 1) {
                moves[newX][newY] = moves[x][y] + 1;
                q.push({newX, newY});
            }
            newX += dx;
            newY += dy;
        }
    }
}
```

This part of the code implements the BFS algorithm. It continues iterating until the queue `q` is empty. In each iteration, it dequeues a position `(x, y)` from the queue and explores all four directions from that position.

For each direction, it calculates the new position `(newX, newY)` by adding the corresponding direction vector. It then checks if this new position is within the grid boundaries and is not blocked by an obstacle (`'X'`).

If the new position is valid and the number of moves required to reach it is less than the currently recorded value in `moves`, it updates the number of moves in `moves` and enqueues the new position `(newX, newY)` into the queue for further exploration.

### Result Calculation:

```cpp
return moves[goalX][goalY];
```

Finally, the function returns the minimum number of moves required to reach the goal position `(goalX, goalY)` as stored in the `moves` array.

### Main Function:

```cpp
int main() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    int startX, startY, goalX, goalY;
    cin >> startX >> startY >> goalX >> goalY;
    int result = minimumMoves(grid, startX, startY, goalX, goalY);
    cout << result << endl;
    return 0;
}
```

In the `main` function, it reads the input grid and coordinates, calls the `minimumMoves` function to find the result, and prints the result.

This code effectively finds the minimum number of moves required to reach the goal position using BFS traversal of the grid.