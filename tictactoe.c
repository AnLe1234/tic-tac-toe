// tic tac toe between a computer or 2 people
#include <stdio.h>
// fucntion to display current board
void display_board(int board[9]) {
    int i = 0;
    for (int j = 0; j < 3; j++) {
        printf("+-----------+\n");
        for (int k = 0; k < 3; k++) {
            printf("| %d ", board[i]);
            i++;
        }
        printf("|\n");
    }
    printf("+-----------+\n");
};
// main function
int main() {
    // user choose which type to play
    int game_type;
    int board[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("1) player vs. player\t2) player vs. computer\n");
    do {
        scanf(": %d", &game_type);
    } while (game_type != 1 || game_type != 2);
    // read input to determine which type
    if (game_type == 1) {
        pvp();
        int turn = 0;
        do {
            int player;
            scanf("Player 1 enter location: %d", player);
            board[player - 1] = "X";
            // check if win
            scanf("Player 2 enter location: %d", player);
            board[player - 1] = "0";
            // check if win
            turn++;
        } while (turn < 5);
        if (turn == 5) {
            printf("Draw!");
        }
    } else {
        pve();
    }
    // loop back until 1 person win/board is full
        // player 1 choose a location
        // display board
        // check if win condition/full board
        // player 2 choose a location
        // displayboard
        // check if win condition/full board
        // print out winner/draw

    return 0;
}