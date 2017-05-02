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
	printf(" _______ _   _______      _______         \n");
	printf("|__   __(_) |__   __|    |__   __|        \n");
	printf("   | |   _  ___| | __ _  ___| | ___   ___ \n");
	printf("   | |  | |/ __| |/ _` |/ __| |/ _ \\ / _ \\ \n");
	printf("   | |  | | (__| | (_| | (__| | (_) |  __/\n");
	printf("   |_|  |_|\\___|_|\\__,_|\\___|_|\\___/ \\___|\n\n");

	if(cur_x == 7) highlight();
	else defaultColor();
	printf("[1] Play Game\n");

	if(cur_x == 8) highlight();
	else defaultColor();
	printf("[2] Credits\n");

	if(cur_x == 9) highlight();
	else defaultColor();
	printf("[3] Exit");
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
	printf(" %c | %c | %c\n",draw[0],draw[1],draw[2]);
	printf("___+___+___\n");
	printf(" %c | %c | %c\n",draw[3],draw[4],draw[5]);
	printf("___+___+___\n");
	printf(" %c | %c | %c\n",draw[6],draw[7],draw[8]);
}