#include "../../sdk/dexsdk.h"

#define KEY_LEFT -106
#define KEY_UP -105
#define KEY_DOWN -104
#define KEY_RIGHT -103
#define KEY_X 32


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
void play(int board[],int move){
	int cur_x = 0, cur_y = 1, x, y, choice = 0;
	int input = 0, index;

	clrscr();
	drawBoard(board);
	printf("\n%d %d\n", cur_x, cur_y);
	update_cursor(cur_x,cur_y);


	while(choice != 1){
		input = getchar();
		printf("%d %c\n", input);
		switch(input){
			case KEY_UP:
				cur_x=cur_x-2;
				break;
			case KEY_DOWN:
				cur_x=cur_x+2;
				break;
			case KEY_LEFT:
				cur_y=cur_y-4;
				break;
			case KEY_RIGHT:
				cur_y=cur_y+4;
				break;
			case KEY_X:
				if(cur_x == 0) x = 0;
				else if(cur_x == 2) x = 1;
				else if(cur_x == 4) x = 2;

				if(cur_y == 1) y = 0;
				else if(cur_y == 5) y = 1;
				else if(cur_y == 9) y = 2;
				int index = (x*3)+y;

				if(board[index] == 0){
					choice = 1;
					board[index] = move;
				}
				break;
			default:
				cur_x = cur_x;
				cur_y = cur_y;
				break;
		}

		clrscr();
		drawBoard(board);
		printf("\n%d %d\n", cur_x, cur_y);
		update_cursor(cur_x,cur_y);

	}

	



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
int main(){
	int board[9] = {1,0,-1,0,0,0,0,0,0};
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
			play(board,player);
		}
		else{
			computerplay(board,computer);
		}
	}

	clrscr();
	drawBoard(board);
	
	return 0;
}