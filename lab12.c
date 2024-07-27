#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void printSolution(int board[], int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i] == j) {
				printf("Q ");
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}
	printf("\n");
}
bool isSafe(int board[], int row, int col) {
	for (int i = 0; i < row; i++) {
		if (board[i] == col || abs(row - i) == abs(col - board[i])) {
			return false;
		}
	}
	return true;
}
bool solveNQueensUtil(int board[], int row, int N) {
	if (row >= N) {
		printSolution(board, N);
		return true;
	}
	for (int col = 0; col < N; col++) {
		if (isSafe(board, row, col)) {
			board[row] = col;
			if (solveNQueensUtil(board, row + 1, N)) {
				return true;
			}
			board[row] = -1;
		}
	}
	return false;
}
void solveNQueens(int N) {
	int *board = (int *)malloc(N * sizeof(int));
	if (board == NULL) {
		printf("Memory allocaƟon failed!\n");
		return;
	}
	for (int i = 0; i < N; i++) {
		board[i] = -1;
	}
	solveNQueensUtil(board, 0, N);
	free(board);
}
int main() {
	int N;
	printf("Enter the number of queens (N): ");
	scanf("%d", &N);
	if (N <= 0) {
		printf("Invalid input! Please enter a posiƟve integer.\n");
		return 1;
	}
	solveNQueens(N);
	return 0;
}
