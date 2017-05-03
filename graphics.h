void highlight(){
	textbackground(WHITE);
	textcolor(BLACK);
}

void defaultColor(){
	textbackground(BLACK);
	textcolor(WHITE);
}

void drawMenu(int cur_x, int cur_y){
	defaultColor();
	printf("\t\t\t\t\t\t _______ _   _______      _______         \n");
	printf("\t\t\t\t\t\t|__   __(_) |__   __|    |__   __|        \n");
	printf("\t\t\t\t\t\t   | |   _  ___| | __ _  ___| | ___   ___ \n");
	printf("\t\t\t\t\t\t   | |  | |/ __| |/ _` |/ __| |/ _ \\ / _ \\ \n");
	printf("\t\t\t\t\t\t   | |  | | (__| | (_| | (__| | (_) |  __/\n");
	printf("\t\t\t\t\t\t   |_|  |_|\\___|_|\\__,_|\\___|_|\\___/ \\___|\n\n");

	defaultColor();
	printf("\t\t\t\t\t\t\t\t\t\t\t");

	if(cur_x == 7) highlight();
	else defaultColor();
	printf("Play Easy\n");

	defaultColor();
	printf("\t\t\t\t\t\t\t\t\t\t\t");
	if(cur_x == 8) highlight();
	else defaultColor();
	printf("Play Hard\n");

	defaultColor();
	printf("\t\t\t\t\t\t\t\t\t\t\t");
	if(cur_x == 9) highlight();
	else defaultColor();
	printf("Exit");
	update_cursor(-1,-1);
}

void drawBoard(int board[]){
	char draw[9];
	int i=0;
	for(i=0;i<9;i++){
		if(board[i]==0) draw[i]=' ';
		else if(board[i] == 1) draw[i]='X';
		else draw[i]='O';
	}
	printf("\t\t\t\t\t\t _____ _____ _____\n");
	printf("\t\t\t\t\t\t|     |     |     |\n");
	printf("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n",draw[0],draw[1],draw[2]);
	printf("\t\t\t\t\t\t|_____|_____|_____|\n");
	printf("\t\t\t\t\t\t|     |     |     |\n");
	printf("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n",draw[3],draw[4],draw[5]);
	printf("\t\t\t\t\t\t|_____|_____|_____|\n");
	printf("\t\t\t\t\t\t|     |     |     |\n");
	printf("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n",draw[6],draw[7],draw[8]);
	printf("\t\t\t\t\t\t|_____|_____|_____|\n");

}