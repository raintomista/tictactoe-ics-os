#define KEY_LEFT -106
#define KEY_UP -105
#define KEY_DOWN -104
#define KEY_RIGHT -103
#define KEY_SPACE 32
#define KEY_ESC 27


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
	write_text(" Computer's Turn",20,20,BLACK,LARGE_FONT);
	write_text(" User's Turn",20,20,LIGHTRED,LARGE_FONT);

	int valid = 0;
	int input = getchar();

	while(valid != 1){
		switch(input){
			case 49:
				if(board[0] == 0){
					drawMove(board, 0, 1, LARGE_FONT);
					board[0] = move;
					valid = 1;
				}
				break;
			case 50:
				if(board[1] == 0){
					drawMove(board, 1, 1, LARGE_FONT);
					board[1] = move;
					valid = 1;
				}
				break;
			case 51:
				if(board[2] == 0){
					drawMove(board, 2, 1, LARGE_FONT);
					board[2] = move;
					valid = 1;
				}
				break;
			case 52:
				if(board[3] == 0){
					drawMove(board, 3, 1, LARGE_FONT);
					board[3] = move;
					valid = 1;
				}
				break;
			case 53:
				if(board[4] == 0){
					drawMove(board, 4, 1, LARGE_FONT);
					board[4] = move;
					valid = 1;
				}
				break;
			case 54:
				if(board[5] == 0){
					drawMove(board, 5, 1, LARGE_FONT);
					board[5] = move;
					valid = 1;
				}
				break;
			case 55:
				if(board[6] == 0){
					drawMove(board, 6, 1, LARGE_FONT);
					board[6] = move;
					valid = 1;
				}
				break;
			case 56:
				if(board[7] == 0){
					drawMove(board, 7, 1, LARGE_FONT);
					board[7] = move;
					valid = 1;
				}
				break;
			case 57:
				if(board[8] == 0){
					drawMove(board, 8, 1, LARGE_FONT);
					board[8] = move;
	 
	    			valid = 1;
				}
				break;
			case KEY_ESC:
				exit(0);
				break;
			default:
				break;
		}
	}
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

void startGame(int difficulty){
	set_graphics(VGA_640X480X16);
	clrscr();
	int board[9] = {0,0,0,0,0,0,0,0,0};
	int playerFlag = rand()%2;
	int player_turn = 0;
	int turn = 0;
	int temp;
	int computer = -1;
	int player = 1;
	if(playerFlag == 0){
		player_turn = 0;
	}
	else if(playerFlag == 1){
		player_turn = 1;

	}

	drawBoard(board, 300, 300);

	for(turn=0;turn<9 && terminal(board)==-1 && check(board,computer)==0;turn++){
		if((turn+player_turn)%2 != 0){
			reprintMoves(board, 0);
			play(board,player);
		}
		else{
			switch(difficulty){
				case 1:
					findGood(board, computer);
					break;
				case 2:
					findBest(board,computer);
					break;
			}
		}
	}

	reprintMoves(board, 0);
	int score = check(board,computer);
	if(check(board,computer)==1){
		write_text(" Computer's Turn",20,20,BLACK,LARGE_FONT);
		write_text(" User's Turn",20,20,BLACK,LARGE_FONT);

   		write_text(" Computer Won!",20,20,CYAN,LARGE_FONT);
	}
	else if(check(board,computer)==-1){
		write_text(" Computer's Turn",20,20,BLACK,LARGE_FONT);
		write_text(" User's Turn",20,20,BLACK,LARGE_FONT);
   		write_text(" Player Won!",20,20,LIGHTRED,LARGE_FONT);
	}
	else{
		write_text(" Computer's Turn",20,20,BLACK,LARGE_FONT);
		write_text(" User's Turn",20,20,BLACK,LARGE_FONT);
   		write_text(" Draw!",20,20,MAGENTA,LARGE_FONT);
	}

	write_text(" Press any button to continue...",300,440,YELLOW,LARGE_FONT);
	getch();

	set_graphics(VGA_640X480X16);
	clrscr();
	drawMenu(500, 375);
}

void select(int selector, int * choice){
	int x = ((WIDTH/2)-(TARGET_WIDTH/2))-1;
	int y = ((HEIGHT/2)-(TARGET_HEIGHT/2))-1;

	switch(selector){
		case 1:
			*choice = 1;
			startGame(*choice);
			break;
		case 2:
			*choice = 2;
			startGame(*choice);
			break;
		case 3:
			*choice = 3;
			break;
	}
}
