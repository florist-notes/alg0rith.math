# Matrices

1. Matrix Operations:
   
Matrix operations involve various mathematical operations performed on matrices, such as addition, subtraction, multiplication, and inversion.

```cpp
#include <iostream>
#include <vector>

// Function to add two matrices
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();

    std::vector<std::vector<int>> result(rows, std::vector<int>(cols, 0));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

int main() {
    // Example matrices
    std::vector<std::vector<int>> matrixA = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<std::vector<int>> matrixB = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};

    // Add matrices
    std::vector<std::vector<int>> resultMatrix = addMatrices(matrixA, matrixB);

    // Display the result
    for (const auto& row : resultMatrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


```

2. Linear Recurrences:
   
Linear recurrences describe a sequence where each term is a linear combination of previous terms. This concept is often used in the context of recursive algorithms and generating functions.

```cpp
#include <iostream>
#include <vector>

// Function to compute the nth term of a linear recurrence
int linearRecurrence(int n) {
    // Initial terms
    int a0 = 1;
    int a1 = 2;

    // Coefficients of the linear recurrence
    int c0 = 2;
    int c1 = 3;

    // Compute the nth term
    for (int i = 2; i <= n; ++i) {
        int currentTerm = c0 * a1 + c1 * a0;
        a0 = a1;
        a1 = currentTerm;
    }

    return a1;
}

int main() {
    int n = 5;

    // Compute the nth term of the linear recurrence
    int result = linearRecurrence(n);

    std::cout << "Term " << n << " of the linear recurrence: " << result << std::endl;

    return 0;
}


```

3. Graphs and Matrices:
   
Graphs can be represented using matrices, such as adjacency matrices or incidence matrices. These representations help perform various graph operations efficiently.

```cpp
#include <iostream>
#include <vector>

// Function to print an adjacency matrix of a graph
void printAdjacencyMatrix(const std::vector<std::vector<int>>& adjacencyMatrix) {
    for (const auto& row : adjacencyMatrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example adjacency matrix of a graph
    std::vector<std::vector<int>> adjacencyMatrix = {{0, 1, 1}, {1, 0, 0}, {1, 0, 0}};

    // Print the adjacency matrix
    std::cout << "Adjacency Matrix:" << std::endl;
    printAdjacencyMatrix(adjacencyMatrix);

    return 0;
}


```

4. Gaussian Elimination:
   
Gaussian elimination is a method used for solving systems of linear equations and finding the reduced row-echelon form of a matrix.

```cpp

#include <iostream>
#include <vector>

// Perform Gaussian elimination to find the reduced row-echelon form of a matrix
void gaussianElimination(std::vector<std::vector<double>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; ++i) {
        // Find the pivot row
        int pivotRow = i;
        for (int k = i + 1; k < rows; ++k) {
            if (std::abs(matrix[k][i]) > std::abs(matrix[pivotRow][i])) {
                pivotRow = k;
            }
        }

        // Swap the current row with the pivot row
        std::swap(matrix[i], matrix[pivotRow]);

        // Make the pivot element 1
        double pivotElement = matrix[i][i];
        for (int k = 0; k < cols; ++k) {
            matrix[i][k] /= pivotElement;
        }

        // Eliminate other rows
        for (int k = 0; k < rows; ++k) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = 0; j < cols; ++j) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    // Example augmented matrix of a system of linear equations
    std::vector<std::vector<double>> augmentedMatrix = {{2, 1, 1, 8}, {-3, -1, 2, -11}, {-2, 1, 2, -3}};

    // Apply Gaussian elimination
    gaussianElimination(augmentedMatrix);

    // Display the reduced row-echelon form
    std::cout << "Reduced Row-Echelon Form:" << std::endl;
    for (const auto& row : augmentedMatrix) {
        for (double element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}


```