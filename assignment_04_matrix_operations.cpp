// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

// -----------------------------------------------------------------------------
// Function to read a matrix from the user
// -----------------------------------------------------------------------------
void readMatrix(int matrix[MAX][MAX], int rows, int cols, const string &name)
{
    cout << "\n--- Entering Matrix " << name << " ---\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "Enter element " << name << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// -----------------------------------------------------------------------------
// Function to display a matrix in an aligned grid
// -----------------------------------------------------------------------------
void displayMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
void transposeMatrix()
{
    int M, N;
    int mat[MAX][MAX], trans[MAX][MAX];

    cout << "\n====== PART A: Transpose a Matrix ======\n";
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    readMatrix(mat, M, N, "A");

    // Compute transpose: trans[j][i] = mat[i][j]
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            trans[j][i] = mat[i][j];
        }
    }

    cout << "\nOriginal Matrix (" << M << " x " << N << "):\n";
    displayMatrix(mat, M, N);

    cout << "\nTransposed Matrix (" << N << " x " << M << "):\n";
    displayMatrix(trans, N, M);
}

// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
void addMatrices()
{
    int M, N;
    int matA[MAX][MAX], matB[MAX][MAX], sum[MAX][MAX];

    cout << "\n====== PART B: Add Two Matrices ======\n";
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;

    readMatrix(matA, M, N, "A");
    readMatrix(matB, M, N, "B");

    // Element-wise addition
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum[i][j] = matA[i][j] + matB[i][j];
        }
    }

    cout << "\nMatrix A:\n";
    displayMatrix(matA, M, N);

    cout << "\nMatrix B:\n";
    displayMatrix(matB, M, N);

    cout << "\nSum (A + B):\n";
    displayMatrix(sum, M, N);
}

// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
void multiplyMatrices()
{
    int M, N, P;
    int matA[MAX][MAX], matB[MAX][MAX], prod[MAX][MAX] = {0};

    cout << "\n====== PART C: Multiply Two Matrices ======\n";

    // Read Matrix A (M x N)
    cout << "--- Matrix A ---\n";
    cout << "Enter number of rows: ";
    cin >> M;
    cout << "Enter number of columns: ";
    cin >> N;
    readMatrix(matA, M, N, "A");

    // Read Matrix B (N x P)
    cout << "--- Matrix B ---\n";
    cout << "Enter number of rows: ";
    int temp;
    cin >> temp;
    // Validate that B's rows == A's columns
    while (temp != N)
    {
        cout << "ERROR: Number of rows in B must equal number of columns in A (" << N << ").\n";
        cout << "Enter number of rows: ";
        cin >> temp;
    }
    cout << "Enter number of columns: ";
    cin >> P;
    readMatrix(matB, N, P, "B");

    // Matrix multiplication: prod[i][j] = sum over k of A[i][k] * B[k][j]
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < P; j++)
        {
            prod[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                prod[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    cout << "\nMatrix A (" << M << " x " << N << "):\n";
    displayMatrix(matA, M, N);

    cout << "\nMatrix B (" << N << " x " << P << "):\n";
    displayMatrix(matB, N, P);

    cout << "\nProduct (A x B) — Result (" << M << " x " << P << "):\n";
    displayMatrix(prod, M, P);
}

// -----------------------------------------------------------------------------
// Main function — runs all three parts
// -----------------------------------------------------------------------------
int main()
{
    cout << "============================================\n";
    cout << "  MATRIX OPERATIONS PROGRAM\n";
    cout << "============================================\n";

    transposeMatrix();
    addMatrices();
    multiplyMatrices();

    cout << "\n============================================\n";
    cout << "  All operations completed. Goodbye!\n";
    cout << "============================================\n";

    return 0;
}


