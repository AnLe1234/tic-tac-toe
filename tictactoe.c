// tic tac toe between a computer or 2 people

// fucntion to display current board

// main function
int main() {
    // user choose which type to play
    int game_type;
    printf("1) player vs. player\t2) player vs. computer\n");
    do {
        scanf(": %d", &game_type);
    } while (game_type != 1 || game_type != 2);
    // read input to determine which type
    if (game_type == 1) {
        pvp();
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