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


void drawSelector(int x, int y, char color, int size){
	write_char(42, x, y, color, size);
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

void drawBoard(int board[], int targetWidth, int targetHeight){
	// char draw[9];
	// int i=0;
	// for(i=0;i<9;i++){
	// 	if(board[i]==0) draw[i]=' ';
	// 	else if(board[i] == 1) draw[i]='X';
	// 	else draw[i]='O';
	// }
	// printf("\t\t\t\t\t\t _____ _____ _____\n");
	// printf("\t\t\t\t\t\t|     |     |     |\n");
	// printf("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n",draw[0],draw[1],draw[2]);
	// printf("\t\t\t\t\t\t|_____|_____|_____|\n");
	// printf("\t\t\t\t\t\t|     |     |     |\n");
	// printf("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n",draw[3],draw[4],draw[5]);
	// printf("\t\t\t\t\t\t|_____|_____|_____|\n");
	// printf("\t\t\t\t\t\t|     |     |     |\n");
	// printf("\t\t\t\t\t\t|  %c  |  %c  |  %c  |\n",draw[6],draw[7],draw[8]);
	// printf("\t\t\t\t\t\t|_____|_____|_____|\n");

	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;
	int increment_x = targetWidth/3;
	int increment_y = targetWidth/3;


	write_char(201, x, y, YELLOW, LARGE_FONT); //Upper Left Border
	drawHorizontalBorder(x+8, (x+targetWidth)-2, y, YELLOW, LARGE_FONT);
	write_char(187, x+targetWidth, y, YELLOW, LARGE_FONT); //Upper Right Border

	drawVerticalBorder(x, y+8, (y+targetHeight)-15, YELLOW, LARGE_FONT);
	write_char(200, x, y+targetHeight, YELLOW, LARGE_FONT); //Lower Left Border


	drawHorizontalBorder(x+8, (x+targetWidth)-2, y+targetHeight, YELLOW, LARGE_FONT);
	drawVerticalBorder(x+targetWidth, y+8, (y+targetHeight)-15, YELLOW, LARGE_FONT);
	write_char(188, x+targetWidth, y+targetHeight, YELLOW, LARGE_FONT); //Lower Right Border

	drawVerticalBorder(x+increment_x, y+8, (y+targetHeight)-9, YELLOW, LARGE_FONT);
	drawVerticalBorder(x+(increment_x*2), y+8, (y+targetHeight)-9, YELLOW, LARGE_FONT);
	drawVerticalBorder(x+(increment_x*3), y+8, (y+targetHeight)-9, YELLOW, LARGE_FONT);

	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*1), YELLOW, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*2), YELLOW, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*3), YELLOW, LARGE_FONT);


	drawHorizontalBorder(x+7, (x+increment_x)-3, y, RED, LARGE_FONT);
	drawVerticalBorder(x+increment_x, y+8, y+increment_y-10, RED, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+increment_x)-3, y+increment_y, RED, LARGE_FONT);


	/*First Tile*/
	int x1 = x+7, x2 = (x+increment_x)-3;
	int y1 = y+8, y2 = y+increment_y-10;
	int TILE1_X = (x1+x2)/2, TILE1_Y = (y1+y2)/2;


	/*Second Tile*/
	x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
	y1 = y+8, y2 = y+increment_y-10;
	int TILE2_X = (x1+x2)/2, TILE2_Y = (y1+y2)/2;


	/*Third Tile*/
	x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
	y1 = y+8, y2 = y+increment_y-10;
	int TILE3_X = (x1+x2)/2, TILE3_Y = (y1+y2)/2;


	write_char(88, TILE1_X, TILE1_Y, YELLOW, LARGE_FONT); //First Tile
	write_char(88, TILE2_X, TILE2_Y, YELLOW, LARGE_FONT); //Second Tile
	write_char(88, TILE3_X, TILE3_Y, YELLOW, LARGE_FONT); //Second Tile


	/*Fourth Tile*/
	x1 = x+7, x2 = (x+increment_x)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-10;
	int TILE4_X = (x1+x2)/2, TILE4_Y = (y1+y2)/2;

	/*Fifth Tile*/
	x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-10;
	int TILE5_X = (x1+x2)/2, TILE5_Y = (y1+y2)/2;


	/*Sixth Tile*/
	x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-10;
	int TILE6_X = (x1+x2)/2, TILE6_Y = (y1+y2)/2;

	write_char(88, TILE4_X, TILE4_Y, YELLOW, LARGE_FONT); //First Tile
	write_char(88, TILE5_X, TILE5_Y, YELLOW, LARGE_FONT); //Second Tile
	write_char(88, TILE6_X, TILE6_Y, YELLOW, LARGE_FONT); //Second Tile


	/*Seventh Tile*/
	x1 = x+7, x2 = (x+increment_x)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-10;
	int TILE7_X = (x1+x2)/2, TILE7_Y = (y1+y2)/2;

	/*Eighth Tile*/
	x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-10;
	int TILE8_X = (x1+x2)/2, TILE8_Y = (y1+y2)/2;


	/*Ninth Tile*/
	x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-10;
	int TILE9_X = (x1+x2)/2, TILE9_Y = (y1+y2)/2;

	write_char(88, TILE7_X, TILE7_Y, YELLOW, LARGE_FONT); //First Tile
	write_char(88, TILE8_X, TILE8_Y, YELLOW, LARGE_FONT); //Second Tile
	write_char(88, TILE9_X, TILE9_Y, YELLOW, LARGE_FONT); //Second Tile






}