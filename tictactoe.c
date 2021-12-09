// * File name: tic-tac-toe.c

#include <stdio.h>

#define LINE printf("+---+---+---+\n");

int main(void) {
	int turn;
	int player, winner, choice, row, col, line, whosturn;

	char board[3][3] = {{'1', '2', '3'},
						{'4', '5', '6'},
						{'7', '8', '9'}};

	player	= 0;
	winner	= 0;
	choice	= 0;
	row		= 0;
	col		= 0;
	line	= 0;

	printf("\nTic-Tac-Toe");
	// Draw the board
	for (turn = 0; turn < 9 && winner == 0; turn++) {
		printf("\n\n");
		LINE
		printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
		LINE
		printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
		LINE
		printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
		LINE

		player = (turn % 2) + 1; //* Select player
		whosturn = (player == 1) ? 'X' : 'O';

		do {
			printf("\nEnter your go, player %c: ", whosturn);
			scanf("%d", &choice);

			row = --choice / 3;
			col = choice % 3;
		}
		while (choice < 0 || choice > 9 || board[row][col] > '9');
		
		board[row][col] = whosturn; // Insert player symbol

		// Check for a winner
		if ((board[0][0] == board[1][1] &&
			 board[0][0] == board[2][2]) ||
			(board[0][2] == board[1][1] &&
			 board[0][2] == board[2][0])) {
				winner = player;
			}
		else {
			for(line = 0; line <= 2; line++) {
				if ((board[line][0] == board[line][1] &&
					 board[line][0] == board[line][2]) ||
					(board[0][line] == board[1][line] &&
					 board[0][line] == board[2][line])) {
						winner = player;
				} // End if check line
			} // End for loop check line
		} // End if else check for winner
	} // End of for loop

	printf("\nGame Finished!");

	printf("\n\n");
	LINE
	printf("| %c | %c | %c |\n", board[0][0], board[0][1], board[0][2]);
	LINE
	printf("| %c | %c | %c |\n", board[1][0], board[1][1], board[1][2]);
	LINE
	printf("| %c | %c | %c |\n", board[2][0], board[2][1], board[2][2]);
	LINE

	if (winner == 0) {
		printf("\nHow boring, it\'s a draw\n");
	}
	else {
		printf("\nPLAYER %c IS THE WINNER!\n");
	}

	return 0;
}
