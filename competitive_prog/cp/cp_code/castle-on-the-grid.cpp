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
