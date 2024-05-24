#include <bits/stdc++.h>

using namespace std;

const double EPSILON = 1e-10;
const int MAX_CELLS = 777;

char maze[MAX_CELLS][MAX_CELLS];
double matrix[MAX_CELLS][MAX_CELLS];
double solution[MAX_CELLS];
int variable[MAX_CELLS];
pair<int, int> tunnels[MAX_CELLS][MAX_CELLS];

int main() {
    int height, width, numTunnels;
    scanf("%d %d %d", &height, &width, &numTunnels);

    // Read the maze
    for (int i = 0; i < height; ++i) {
        scanf("%s", maze[i]);
    }

    // Initialize tunnels
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            tunnels[i][j] = {i, j};
        }
    }

    // Read tunnel connections
    for (int i = 0; i < numTunnels; ++i) {
        int r1, c1, r2, c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; c1--; r2--; c2--;
        tunnels[r1][c1] = {r2, c2};
        tunnels[r2][c2] = {r1, c1};
    }

    // Initialize identity matrix
    for (int i = 0; i < height * width; ++i) {
        matrix[i][i] = 1.0;
    }

    int start = -1;

    // Build the matrix for Gaussian elimination
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (maze[i][j] == '#' || maze[i][j] == '*') continue;

            int currentCell = i * width + j;
            if (maze[i][j] == 'A') {
                start = currentCell;
            } 
            if (maze[i][j] == '%') {
                matrix[currentCell][height * width] = 1.0;
                continue;
            }

            vector<pair<int, int>> neighbors;
            for (int dx = -1; dx <= 1; ++dx) {
                for (int dy = -1; dy <= 1; ++dy) {
                    if (abs(dx) + abs(dy) == 1) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && nj >= 0 && ni < height && nj < width && maze[ni][nj] != '#') {
                            neighbors.push_back(tunnels[ni][nj]);
                        }
                    }
                }
            }

            if (!neighbors.empty()) {
                double probability = 1.0 / neighbors.size();
                for (auto [ni, nj] : neighbors) {
                    int neighborCell = ni * width + nj;
                    matrix[currentCell][neighborCell] -= probability;
                }
            }
        }
    }

    int numCells = height * width;
    int column = 0;

    // Gaussian elimination
    for (int row = 0; row < numCells; ++row) {
        variable[row] = -1;
        while (column < numCells) {
            int pivotRow = row;
            for (int i = row; i < numCells; ++i) {
                if (fabs(matrix[i][column]) > fabs(matrix[pivotRow][column])) {
                    pivotRow = i;
                }
            }
            if (fabs(matrix[pivotRow][column]) < EPSILON) {
                column++;
                continue;
            }
            swap(matrix[row], matrix[pivotRow]);
            for (int i = row + 1; i < numCells; ++i) {
                double coeff = matrix[i][column] / matrix[row][column];
                for (int j = column; j <= numCells; ++j) {
                    matrix[i][j] -= coeff * matrix[row][j];
                }
            }
            variable[row] = column;
            break;
        }
    }

    // Back-substitution
    for (int row = numCells - 1; row >= 0; --row) {
        int col = variable[row];
        if (col == -1) continue;
        solution[col] = matrix[row][numCells] / matrix[row][col];
        for (int i = row - 1; i >= 0; --i) {
            matrix[i][numCells] -= matrix[i][col] * solution[col];
            matrix[i][col] = 0;
        }
    }

    printf("%.17f\n", solution[start]);

    return 0;
}
