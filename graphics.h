#define LARGE_FONT 1
#define SMALL_FONT 0

int max_colors=255;
int width=640;
int height=480;
int TILE1_X, TILE1_Y;
int TILE2_X, TILE2_Y;
int TILE3_X, TILE3_Y;
int TILE4_X, TILE4_Y;
int TILE5_X, TILE5_Y;
int TILE6_X, TILE6_Y;
int TILE7_X, TILE7_Y;
int TILE8_X, TILE8_Y;
int TILE9_X, TILE9_Y;

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

void drawMove(int board[], int index, int x, int y, char color, int size){
	if(board[index]==-1) write_char(79, x, y, color, size); //Draw Space
	else if(board[index] == 1) write_char(88, x, y, color, size);
	else{
		write_char(91, x-10, y, color, size);
		switch(index){
			case 0:
				write_char(49, x, y, color, size);
				break;
			case 1:
				write_char(50, x, y, color, size);
				break;
			case 2:
				write_char(51, x, y, color, size);
				break;
			case 3:
				write_char(52, x, y, color, size);
				break;
			case 4:
				write_char(53, x, y, color, size);
				break;
			case 5:
				write_char(54, x, y, color, size);
				break;
			case 6:
				write_char(55, x, y, color, size);
				break;
			case 7:
				write_char(56, x, y, color, size);
				break;
			case 8:
				write_char(57, x, y, color, size);
				break;
		}
		write_char(93, x+10	, y, color, size);

	}
}

void reprintMoves(int board[], char color){
	drawMove(board, 0, TILE1_X, TILE1_Y, color, LARGE_FONT); //First Tile
	drawMove(board, 1, TILE2_X, TILE2_Y, color, LARGE_FONT); //Second Tile
	drawMove(board, 2, TILE3_X, TILE3_Y, color, LARGE_FONT); //Third Tile

	drawMove(board, 3, TILE4_X, TILE4_Y, color, LARGE_FONT); //Fourth Tile
	drawMove(board, 4, TILE5_X, TILE5_Y, color, LARGE_FONT); //Fifth Tile
	drawMove(board, 5, TILE6_X, TILE6_Y, color, LARGE_FONT); //Sixth Tile

	drawMove(board, 6, TILE7_X, TILE7_Y, color, LARGE_FONT); //Seventh Tile
	drawMove(board, 7, TILE8_X, TILE8_Y, color, LARGE_FONT); //Eight Tile
	drawMove(board, 8, TILE9_X, TILE9_Y, color, LARGE_FONT); //Nine Tile
}

void drawBoard(int board[], int targetWidth, int targetHeight){
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;
	int increment_x = targetWidth/3;
	int increment_y = targetWidth/3;

	// Top Border
	write_char(201, x, y, YELLOW, LARGE_FONT); //Upper Left Border
	drawHorizontalBorder(x+8, (x+targetWidth)-2, y, YELLOW, LARGE_FONT);
	write_char(187, x+targetWidth, y, YELLOW, LARGE_FONT); //Upper Right Border

	// Left and Right Border
	drawVerticalBorder(x, y+8, (y+targetHeight)-15, YELLOW, LARGE_FONT); //Left Border
	drawVerticalBorder(x+targetWidth, y+8, (y+targetHeight)-15, YELLOW, LARGE_FONT); //Right Border

	// Bottom Border
	write_char(200, x, y+targetHeight, YELLOW, LARGE_FONT); //Lower Left Border
	drawHorizontalBorder(x+8, (x+targetWidth)-2, y+targetHeight, YELLOW, LARGE_FONT);
	write_char(188, x+targetWidth, y+targetHeight, YELLOW, LARGE_FONT); //Lower Right Border

	// Vertical Grid
	drawVerticalBorder(x+increment_x, y+8, (y+targetHeight)-9, YELLOW, LARGE_FONT);
	drawVerticalBorder(x+(increment_x*2), y+8, (y+targetHeight)-9, YELLOW, LARGE_FONT);
	drawVerticalBorder(x+(increment_x*3), y+8, (y+targetHeight)-9, YELLOW, LARGE_FONT);

	// Horizontal Grid
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*1), YELLOW, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*2), YELLOW, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*3), YELLOW, LARGE_FONT);

	/*First Tile*/
	int x1 = x+7, x2 = (x+increment_x)-3;
	int y1 = y+8, y2 = y+increment_y-10;
	TILE1_X = (x1+x2)/2, TILE1_Y = (y1+y2)/2;

	/*Second Tile*/
	x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
	y1 = y+8, y2 = y+increment_y-10;
	TILE2_X = (x1+x2)/2, TILE2_Y = (y1+y2)/2;

	/*Third Tile*/
	x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
	y1 = y+8, y2 = y+increment_y-10;
	TILE3_X = (x1+x2)/2, TILE3_Y = (y1+y2)/2;

	/*Fourth Tile*/
	x1 = x+7, x2 = (x+increment_x)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-10;
	TILE4_X = (x1+x2)/2, TILE4_Y = (y1+y2)/2;

	/*Fifth Tile*/
	x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-10;
	TILE5_X = (x1+x2)/2, TILE5_Y = (y1+y2)/2;

	/*Sixth Tile*/
	x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-10;
	TILE6_X = (x1+x2)/2, TILE6_Y = (y1+y2)/2;

	/*Seventh Tile*/
	x1 = x+7, x2 = (x+increment_x)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-10;
	TILE7_X = (x1+x2)/2, TILE7_Y = (y1+y2)/2;

	/*Eighth Tile*/
	x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-10;
	TILE8_X = (x1+x2)/2, TILE8_Y = (y1+y2)/2;

	/*Ninth Tile*/
	x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-10;
	TILE9_X = (x1+x2)/2, TILE9_Y = (y1+y2)/2;

	drawMove(board, 0, TILE1_X, TILE1_Y, YELLOW, LARGE_FONT); //First Tile
	drawMove(board, 1, TILE2_X, TILE2_Y, YELLOW, LARGE_FONT); //Second Tile
	drawMove(board, 2, TILE3_X, TILE3_Y, YELLOW, LARGE_FONT); //Third Tile

	drawMove(board, 3, TILE4_X, TILE4_Y, YELLOW, LARGE_FONT); //Fourth Tile
	drawMove(board, 4, TILE5_X, TILE5_Y, YELLOW, LARGE_FONT); //Fifth Tile
	drawMove(board, 5, TILE6_X, TILE6_Y, YELLOW, LARGE_FONT); //Sixth Tile

	drawMove(board, 6, TILE7_X, TILE7_Y, YELLOW, LARGE_FONT); //Seventh Tile
	drawMove(board, 7, TILE8_X, TILE8_Y, YELLOW, LARGE_FONT); //Eight Tile
	drawMove(board, 8, TILE9_X, TILE9_Y, YELLOW, LARGE_FONT); //Nine Tile
}

