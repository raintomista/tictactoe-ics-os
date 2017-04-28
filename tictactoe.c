#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int check(int board[]){
	if(board[0] != 0 && board[0] == board[1] && board[0] == board[2]) return board[0];
	else if(board[3] != 0 && board[3] == board[4] && board[3] == board[5]) return board[3];
	else if(board[6] != 0 && board[6] == board[7] && board[6] == board[8]) return board[6];
	else if(board[0] != 0 && board[0] == board[3] && board[0] == board[6]) return board[0];
	else if(board[1] != 0 && board[1] == board[4] && board[1] == board[7]) return board[1];
	else if(board[2] != 0 && board[2] == board[5] && board[2] == board[8]) return board[2];
	else if(board[0] != 0 && board[0] == board[4] && board[0] == board[8]) return board[0];
	else if(board[6] != 0 && board[6] == board[4] && board[6] == board[2]) return board[6];
	else return 0;	
}
void play(int board[],int move){
	int index;
	printf("Enter move [1-9]:");
	scanf("%d",&index);	
	while(board[index-1] != 0){
		printf("Space is already Occupied!\n");
		printf("Enter move [1-9]:");
		scanf("%d",&index);		
	}
	board[index-1] = move;
}
void drawBoard(int board[]){
	char draw[9];
	int i=0;
	for(i=0;i<9;i++){
		if(board[i]==0) draw[i]=' ';
		else if(board[i] == 1) draw[i]='X';
		else draw[i]='O';
	}
	printf(" %c | %c | %c\n",draw[0],draw[1],draw[2]);
	printf("___+___+___\n");
	printf(" %c | %c | %c\n",draw[3],draw[4],draw[5]);
	printf("___+___+___\n");
	printf(" %c | %c | %c\n",draw[6],draw[7],draw[8]);

}
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
    printf("%d , %d\n",value,move);
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
    printf("MOVE: %d\n",move);
    board[move]=computer;
}
int main(){
	int board[9] = {0,0,0,0,0,0,0,0,0};
	int playerFlag = rand()%2;
	int player,computer;
	int player_turn = 0;
	int turn = 0;
	int temp;
	if(playerFlag == 0){
		player = 1;
		computer = -1;
		player_turn = 0;
		printf("%d\n",player);
	}
	else if(playerFlag == 1){
		computer = 1;
		player = -1;
		player_turn = 1;
		printf("%d\n",computer);
	}
	for(turn=0;turn<9 && check(board)== 0;turn++){
		if((turn+player_turn)%2 != 0){
			drawBoard(board);
			printf("\n Player's Turn\n");
			play(board,player);
		}
		else{
			drawBoard(board);
			printf("\n Computer's Turn\n");
			computerplay(board,computer);
		}
	}
	drawBoard(board);
	return 0;
}