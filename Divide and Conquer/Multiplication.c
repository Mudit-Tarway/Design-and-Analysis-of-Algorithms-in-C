#include <stdio.h>
#include <stdlib.h>

// Function to add two matrices
void addMatrix(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] + b[i][j];
}

// Function to subtract two matrices
void subMatrix(int n, int a[n][n], int b[n][n], int result[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            result[i][j] = a[i][j] - b[i][j];
}

// Recursive function for divide and conquer multiplication
void multiplyMatrix(int n, int A[n][n], int B[n][n], int C[n][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int a11[k][k], a12[k][k], a21[k][k], a22[k][k];
    int b11[k][k], b12[k][k], b21[k][k], b22[k][k];
    int c11[k][k], c12[k][k], c21[k][k], c22[k][k];
    int temp1[k][k], temp2[k][k];

    // Dividing A into 4 submatrices
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + k];
            a21[i][j] = A[i + k][j];
            a22[i][j] = A[i + k][j + k];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + k];
            b21[i][j] = B[i + k][j];
            b22[i][j] = B[i + k][j + k];
        }
    }

    // c11 = a11*b11 + a12*b21
    multiplyMatrix(k, a11, b11, temp1);
    multiplyMatrix(k, a12, b21, temp2);
    addMatrix(k, temp1, temp2, c11);

    // c12 = a11*b12 + a12*b22
    multiplyMatrix(k, a11, b12, temp1);
    multiplyMatrix(k, a12, b22, temp2);
    addMatrix(k, temp1, temp2, c12);

    // c21 = a21*b11 + a22*b21
    multiplyMatrix(k, a21, b11, temp1);
    multiplyMatrix(k, a22, b21, temp2);
    addMatrix(k, temp1, temp2, c21);

    // c22 = a21*b12 + a22*b22
    multiplyMatrix(k, a21, b12, temp1);
    multiplyMatrix(k, a22, b22, temp2);
    addMatrix(k, temp1, temp2, c22);

    // Combine results into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = c11[i][j];
            C[i][j + k] = c12[i][j];
            C[i + k][j] = c21[i][j];
            C[i + k][j + k] = c22[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter size of square matrix (power of 2): ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    // Initialize C with zeros
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = 0;

    multiplyMatrix(n, A, B, C);

    printf("Resultant Matrix C:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
