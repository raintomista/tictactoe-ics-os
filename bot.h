int minmax(int board[9],int isMax);
int get_min(int m,int v){
    if(m>v){
        return v;
    }
    return m;
}

int get_max(int m,int v){
    if(m<v){
        return v;
    }
    return m;
}
int min_val(int board[9],int isMax){
    int m=INT_MAX;
    int i;
    int v;
    for(i=0;i<9;i++){
        if(board[i]==0){
            board[i] = 1;
            v = minmax(board,isMax*-1);
            board[i] = 0;
            m = get_min(m,v);
        }
    }
    //printf("MIN:%d\n",m);
    return m;
}
int max_val(int board[9],int isMax){
    int m=INT_MIN;
    int i;
    int v;
    for(i=0;i<9;i++){
        if(board[i]==0){
            board[i] = -1;
            v = minmax(board,isMax*-1);
            board[i] = 0;
            m = get_max(m,v);
        }
    }
    //printf("MAX:%d\n",m);
    return m;
}

int minmax(int board[9],int isMax) {
    int score = check(board,-1);
    //printf("SCORE: %d\n",score);
    if(score == 1) {
        return 1;
    }
    else if(score == -1){
        return -1;
    }
    else if(terminal(board)==1){
    //  printf("UTILITY\n");
        return score;
    }
    else if(isMax==1){ /*this pass isMax?*/
    //  printf("MAX\n");
        return max_val(board,isMax);
    }
    //printf("MIN\n");
    return min_val(board,isMax);
}

void findBest(int board[9],int computer){
    int move;
    int value = INT_MIN;
    int i;

    clrscr();
    printf("\nAI's Turn\n");
    drawBoard(board);
    update_cursor(-1,-1);
    delay(20);
    
    for(i=0;i<9;i++){
        if(board[i] == 0) {
            board[i] = computer;
            int new_value = minmax(board, -1);
            board[i] = 0;
            if(new_value > value) {
                // printf("newval:%d value:%d\n",new_value,value);
                value = new_value;
                move = i;
            }
        }
    }
    // printf("BEST: %d\n",move);
    board[move]=computer; //do best move
}


void findGood(int board[9],int computer){
    int move = rand()%10;

    clrscr();
    printf("\nAI's Turn\n");
    drawBoard(board);
    update_cursor(-1,-1);
    delay(20);

    while(board[move]!=0){
        move = rand()%10;
    }
    board[move] = computer;
}