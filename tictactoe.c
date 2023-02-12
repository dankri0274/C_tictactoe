#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#define LINE printf("+---+---+---+\n");
#define clearScreen printf("\e[1;1H\e[2J"); // Clear screen

int main() {
	int turn;
	int player, winner, choice, row, col, line;

	player = 0;
	winner = 2;
	choice = 0;
	row    = 0;
	col    = 0;
	line   = 0;

	bool gameOver = false;

	char playerNames[2][16];
	char playerSymbols[2];

	char board[3][3] = {
		{'1', '2', '3'},
		{'4', '5', '6'},
		{'7', '8', '9'}
	};
	
	for (int i = 0; i < 2; i++) {
		clearScreen;
		printf("Player %d, what is your name: ", i + 1);
		scanf(" %15[^\n]%*c", playerNames[i]);
	}
	
	for (int i = 0; i < 2; i++) {
		clearScreen;
		printf("%s, choose symbol to use: ", playerNames[i]);
		scanf(" %c", &playerSymbols[i]);
	}

	if (playerSymbols[0] == playerSymbols[1]) {
		printf("\nBoth players has chosen the same character!\nPlease choose another character.\n\n");
		return 1;
	}

	clearScreen;

	for (turn = 0; turn < 9 && !gameOver; turn++) {
		LINE
		printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
		LINE
		printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
		LINE
		printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
		LINE

		if (turn % 2 == 0) { player = 0; }
		else               { player = 1; }

		do {
			printf("%s, it\'s your turn: ", playerNames[player]);
			scanf("%d", &choice);

			row = --choice / 3;
			col = choice % 3;
		}
		while (choice < 0 || choice > 9 || board[row][col] > '9');

		board[row][col] = playerSymbols[player]; // Insert player symbol

		if ((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
			(board[0][2] == board[1][1] && board[0][2] == board[2][0])) {
				winner = player;
				gameOver = true;
			}
		else {
			for (line = 0; line <= 2; line++) {
				if ((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
					(board[0][line] == board[1][line] && board[0][line] == board[2][line])) {
						winner = player;
						gameOver = true;
				}

				clearScreen
			}
		}
	}

	if (winner != 0 && winner != 1) {
		printf("How boring, it\'s a draw\n");
	}
	else {
		printf("PLAYER \"%s\" WINS!\n", playerNames[winner]);
	}

	Sleep(5000);

	return 0;
}
