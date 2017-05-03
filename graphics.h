#define LARGE_FONT 1
#define SMALL_FONT 0

int max_colors=255;
int width=640;
int height=480;

void highlight(){
	textbackground(WHITE);
	textcolor(BLACK);
}

void defaultColor(){
	textbackground(BLACK);
	textcolor(WHITE);
}

void drawHorizontalBorder(int start_x, int end_x, int y, char color, int size){
	while(start_x < end_x){
   		write_char(205, start_x, y, color, size);
		start_x+=5;
	}
}

void drawVerticalBorder(int x, int start_y, int end_y, char color, int size){
	while(start_y < end_y){
   		write_char(186, x, start_y, color, size);
		start_y+=1;
	}
}

void drawScreenBorders(int targetWidth, int targetHeight){
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;

	write_char(201, x, y, YELLOW, LARGE_FONT); //Upper Left Border
	drawHorizontalBorder(x+8, (x+targetWidth)-2, y, YELLOW, LARGE_FONT);
	write_char(187, x+targetWidth, y, YELLOW, LARGE_FONT); //Upper Right Border

	drawVerticalBorder(x, y+8, (y+targetHeight)-15, YELLOW, LARGE_FONT);
	write_char(200, x, y+targetHeight, YELLOW, LARGE_FONT); //Lower Left Border


	drawHorizontalBorder(x+8, (x+targetWidth)-2, y+targetHeight, YELLOW, LARGE_FONT);
	drawVerticalBorder(x+targetWidth, y+8, (y+targetHeight)-15, YELLOW, LARGE_FONT);
	write_char(188, x+targetWidth, y+targetHeight, YELLOW, LARGE_FONT); //Lower Right Border
}


void screenLogo(int x, int y, int spacing){
	write_text(" _______ _   _______      _______         ",x, y+(1*spacing),YELLOW,LARGE_FONT);
	write_text("|__   __(_) |__   __|    |__   __|        ",x, y+(2*spacing),YELLOW,LARGE_FONT);
	write_text("   | |   _  ___| | __ _  ___| | ___   ___ ",x, y+(3*spacing),YELLOW,LARGE_FONT);
	write_text("   | |  | |/ __| |/ _` |/ __| |/ _ \\ / _ \\ ",x, y+(4*spacing),YELLOW,LARGE_FONT);
	write_text("   | |  | | (__| | (_| | (__| | (_) |  __/",x, y+(5*spacing),YELLOW,LARGE_FONT);
	write_text("   |_|  |_|\\___|_|\\__,_|\\___|_|\\___/ \\___|",x, y+(6*spacing),YELLOW,LARGE_FONT);
}


void drawMenu(int targetWidth, int targetHeight){
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;

	drawScreenBorders(targetWidth, targetHeight);
	screenLogo(x+58, y+50, 13);

	write_text("Play Easy", x+208, y+200,YELLOW,LARGE_FONT);
	write_text("Play Hard", x+208, y+225,YELLOW,LARGE_FONT);
	write_text("Exit", x+208, y+250,YELLOW,LARGE_FONT);
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