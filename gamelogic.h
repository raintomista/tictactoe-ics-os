#define KEY_LEFT -106
#define KEY_UP -105
#define KEY_DOWN -104
#define KEY_RIGHT -103
#define KEY_SPACE 32
#define KEY_ESC 27


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
	int cur_x = 4, cur_y = 21, x = 0, y = 0, choice = 0, base_y;
	int input = 0, index;
	while(choice != 1){
		clrscr();
		printf("\nUser's Turn\n");
		drawBoard(board);
		printf("\n");
		highlight();
		printf("[ESC]");
		defaultColor();
		printf(" Exit \t");

		highlight();
		printf("[ARROW KEYS]");
		defaultColor();
		printf(" Navigation \t");

		highlight();
		printf("[SPACE]");
		defaultColor();
		printf(" Finalize move \t");

		update_cursor(cur_x,cur_y);

		input = getchar();
		switch(input){
			case KEY_UP:
				cur_x = (cur_x-3) < 4 ? 10 : cur_x-3;
				x = (x-1) < 0 ? 2 : x-1;
				break;
			case KEY_DOWN:
				cur_x = (cur_x+3) > 10 ? 4 : cur_x+3;
				x = (x+1) > 2 ? 0 : x+1;
				break;
			case KEY_LEFT:
				cur_y = (cur_y-6) < 21 ? 33 : cur_y-6;
				y = (y-1) < 0 ? 2 : y-1;
				break;
			case KEY_RIGHT:
				cur_y = (cur_y+6) > 33 ? 21 : cur_y+6;
				y = (y+1) > 2 ? 0 : y+1;
				break;
			case KEY_SPACE:
				index = (x*3)+y;
				if(board[index] == 0){
					choice = 1;
					board[index] = move;
				}
				break;
			case KEY_ESC:
				exit(0);
				break;
			default:
				cur_x = cur_x;
				cur_y = cur_y;
				break;
		}
	}
}

void startGame(){
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
	}
	else if(playerFlag == 1){
		computer = 1;
		player = -1;
		player_turn = 1;

	}
	for(turn=0;turn<9 && check(board)== 0;turn++){
		if((turn+player_turn)%2 != 0){
			play(board,player);
		}
		else{
			computerplay(board,computer);
		}
	}

	clrscr();
	printf("\n____ WINS!\n");
	drawBoard(board);
	printf("\nPress any button to continue...\n");
	getch();
}

void select(int cur_x, int * choice){
	switch(cur_x){
		case 7:
			*choice = 1;
			startGame();
			break;
		case 8:
			*choice = 2;
			break;
		case 9:
			*choice = 3;
			break;
	}
}
