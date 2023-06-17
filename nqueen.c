#include <stdio.h>
#include <stdlib.h>

int isSafe(int board[], int row, int col) {
    for (int i = 0; i < row; i++) {
        // Check if there is a queen in the same column or diagonals
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row)
            return 0;
    }
    return 1;
}

void printBoard(int board[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i] == j)
                printf("Q ");
            else
                printf("_ ");
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueens(int board[], int row, int size) {
    if (row == size) {
        // All queens have been placed, print the board configuration
        printBoard(board, size);
        return;
    }

    for (int col = 0; col < size; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen at (row, col)
            board[row] = col;

            // Move on to the next row
            solveNQueens(board, row + 1, size);
        }
    }
}

int main() {
    int size;
    printf("Enter the board size (N): ");
    scanf("%d", &size);

    int *board = (int *)malloc(size * sizeof(int));

    solveNQueens(board, 0, size);

    free(board);
    return 0;
}
