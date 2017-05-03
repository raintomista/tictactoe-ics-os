#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int player_turn = 0;
int turn = 0;
int player,computer,playerFlag;
int minmax(int board[9],int isMax);
int check(int board[],int computer){
	if(board[0] != 0 && board[0] == board[1] && board[0] == board[2]){
		if(board[0] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[3] != 0 && board[3] == board[4] && board[3] == board[5]){
		if(board[3] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[6] != 0 && board[6] == board[7] && board[6] == board[8]){
		if(board[6] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[0] != 0 && board[0] == board[3] && board[0] == board[6]){
		if(board[0] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[1] != 0 && board[1] == board[4] && board[1] == board[7]){
		if(board[1] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[2] != 0 && board[2] == board[5] && board[2] == board[8]){
		if(board[2] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[0] != 0 && board[0] == board[4] && board[0] == board[8]){
		if(board[0] == computer){
			return 1;
		}
		return -1;
	}
	else if(board[6] != 0 && board[6] == board[4] && board[6] == board[2]){
		if(board[6] == computer){
			return 1;
		}
		return -1;
	}
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
int terminal(int board[9]){
	int i;
	for(i=0;i<9;i++){
		if(board[i] == 0){
			return -1;
		}
	}
	return 1;
}
void computerPlay(int board[9],int computer){
	int move = rand()%10;
	while(board[move]!=0){
		move = rand()%10;
		printf("%d\n",move);
	}
	board[move] = computer;
}
int main(){
	int board[9] = {0,0,0,0,0,0,0,0,0};
	playerFlag = rand()%2;
	int temp;
	computer = -1;
	player = 1;
	if(playerFlag == 0){ /*check this*/
		player_turn = 0;
		printf("%d\n",player);
	}
	else if(playerFlag == 1){
		player_turn = 1;
		printf("%d\n",computer);
	}
	for(turn=0;turn<9 && terminal(board)==-1 && check(board,computer)==0;turn++){
		if((turn+player_turn)%2 != 0){
			drawBoard(board);
			printf("\n Player's Turn\n");
			play(board,player);
		}
		else{
			drawBoard(board);
			printf("\n Computer's Turn\n");
			computerPlay(board,computer);
		}
	}
	int score = check(board,computer);
	if(check(board,computer)==1){
		//printf("SCORE: %d\n",score);
		printf("Computer Won!\n");
	}
	else if(check(board,computer)==-1){
		//printf("SCORE: %d\n",score);
		printf("Player Won!\n");
	}
	else{
		printf("Draw\n");
	}
	drawBoard(board);
	return 0;
}