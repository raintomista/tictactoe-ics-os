int minmax(int board[9], int computer) {
    int winner = check(board);
    //printf("%d\n",winner);
    if(winner != 0) return winner*computer;
    int move = -1;
    int value = INT_MIN;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = computer;
            int new_value = -minmax(board, computer*-1);
            if(new_value > value) {
                value = new_value;
                move = i;
            }
            board[i] = 0;
        }
    }
    // printf("%d , %d\n",value,move);
    if(move == -1) return 0;
    return value;
}

void computerplay(int board[9],int computer) {
    int move = -1;
    int value = INT_MIN;
    int i;
    for(i = 0; i < 9; ++i) {
        if(board[i] == 0) {
            board[i] = computer;
            int new_value = -minmax(board, -1);
            board[i] = 0;
            if(new_value > value) {
                value = new_value;
                move = i;
            }
        }
    }
    // printf("MOVE: %d\n",move);
    board[move]=computer;
}