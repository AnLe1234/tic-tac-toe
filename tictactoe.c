// tic tac toe between a computer or 2 people
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// fucntion to display current board
void display_board(char *board) {
    int i = 0;
    for (int j = 0; j < 3; j++) {
        printf("+-----------+\n");
        for (int k = 0; k < 3; k++) {
            printf("| %c ", board[i]);
            i++;
        }
        printf("|\n");
    }
    printf("+-----------+\n");
};

void player_turn(char *board, char symbol) {
    int row, col;
    do {
        printf("Enter location (row column): ");
        scanf("%d %d", &row, &col);
        if (row > 3 || col > 3 || row < 1 || col < 1) {
            printf("Enter limit co-ordinate.\n");
        } else if (board[(3 * (row - 1) + (col - 1))] != ' ') {
            printf("Location taken.\n");
        } else {
            board[3 * (row - 1) + (col - 1)] = symbol;
            break;
        }
    } while (1);
    // board[row-1][col-1] = symbol;
};

int check_win(char *board, char symbol) {
    int win = 0;
    if ((board[0] && board[1] && board[2])  == symbol
        || (board[0] && board[4] && board[8]) == symbol
        || (board[0] && board[3] && board[6]) == symbol
        || (board[2] && board[4] && board[6]) == symbol
        || (board[2] && board[5] && board[8]) == symbol
        || (board[1] && board[4] && board[7]) == symbol
        || (board[3] && board[4] && board[5]) == symbol
        || (board[6] && board[7] && board[8]) == symbol
        ) {
        win = 1;
    }
    return win;
};
void computer_turn(char *board, char symbol) {
    time_t t;
    int rand_location;
    printf("Computer's turn");
    do {
        rand_location = rand() % 10;
    } while (board[rand_location] != ' ');
    board[rand_location] = symbol;
}
// main function
int main() {
    // user choose which type to play
    int game_type = 0;
    char board[9] = {' ', ' ', ' ',
                     ' ', ' ', ' ',
                     ' ', ' ', ' '};
    printf("1) player vs. player\t2) player vs. computer");
    // do {
    scanf("%d", &game_type);
    // } while (game_type != 1 || game_type != 2);
    printf("%d", game_type);
    // read input to determine which type
    int max_turn = 9;
    char symbol;
    display_board(board);
    if (game_type == 1) {
        // pvp();
        // int turn = 0;
        // do {
        //     int player;
        //     scanf("Player 1 enter location: %d", player);
        //     board[player - 1] = "X";
        //     // check if win
        //     scanf("Player 2 enter location: %d", player);
        //     board[player - 1] = "0";
        //     // check if win
        //     turn++;
        // } while (turn < 5);
        // if (turn == 5) {
        //     printf("Draw!");
        // }
        while (max_turn != 0) {
            if (max_turn % 2 == 1) {
                symbol = 'X';
                printf("Player 1\n");
            } else {
                symbol = 'O';
                printf("Player 2\n");
            }
            player_turn(board, symbol);
            display_board(board);
            if (check_win(board, symbol) == 1 ) {
                if (symbol == 'X') {
                    printf("Player 1 win");
                }
                else {
                    printf("Player 2 win");
                }
                break;
            }
            max_turn--;
        }
    }
    if (max_turn == 0) {
        printf("Draw!\n");
    }
    // } else {
    //     pve();
    // }

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