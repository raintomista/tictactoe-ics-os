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

void drawLine(int character, int start_x, int end_x, int y, char color, int size){
	while(start_x < end_x){
   		write_char(character, start_x, y, color, size);
		start_x+=4;
	}
}

void drawHorizontalBorder(int start_x, int end_x, int y, char color, int size){
	while(start_x < end_x){
   		write_char(220, start_x, y, color, size);
		start_x+=5;
	}
}

void drawVerticalBorder(int x, int start_y, int end_y, char color, int size){
	while(start_y < end_y){
   		write_char(223, x, start_y, color, size);
		start_y+=1;
	}
}

void drawScreenBorders(int targetWidth, int targetHeight){
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;


	int tempy = y;

	// while(tempy < targetHeight){
	// 	int tempx = x;
	// 	while(tempx < targetWidth){
	// 		write_char(178, tempx, tempy, LIGHTCYAN, LARGE_FONT);
	// 		tempx+=5;
	// 	}
	// 	tempy+=5;
	// }

	drawLine(178, x+8, (x+targetWidth)-7, y+16, LIGHTCYAN, LARGE_FONT);
	drawLine(178, x+8, (x+targetWidth)-7, y+targetHeight-9, LIGHTRED, LARGE_FONT);

	drawHorizontalBorder(x, (x+targetWidth)+3, y, DARKGRAY, LARGE_FONT);
	drawVerticalBorder(x, y+8, (y+targetHeight)+3, DARKGRAY, LARGE_FONT);

	drawHorizontalBorder(x, (x+targetWidth)+3, y+targetHeight, DARKGRAY, LARGE_FONT);
	drawVerticalBorder(x+targetWidth, y+8, (y+targetHeight)+3, DARKGRAY, LARGE_FONT);

	write_text("[ARROW KEYS]",x+75, y+310, WHITE, LARGE_FONT);
	write_text("             Navigate            Choose",x+75, y+310, LIGHTGRAY, LARGE_FONT);
	write_text("                         [SPACE]       ",x+75, y+310, WHITE, LARGE_FONT);


}


void screenLogo(int x, int y, int spacing){
	write_text(" _______ _   _______      _______         ",x, y+(1*spacing),LIGHTRED,LARGE_FONT);
	write_text("|__   __(_) |__   __|    |__   __|        ",x, y+(2*spacing),LIGHTRED,LARGE_FONT);
	write_text("   | |   _  ___| | __ _  ___| | ___   ___ ",x, y+(3*spacing),LIGHTRED,LARGE_FONT);
	write_text("   | |  | |/ __| |/ _` |/ __| |/ _ \\ / _ \\ ",x, y+(4*spacing),LIGHTRED,LARGE_FONT);
	write_text("   | |  | | (__| | (_| | (__| | (_) |  __/",x, y+(5*spacing),LIGHTRED,LARGE_FONT);
	write_text("   |_|  |_|\\___|_|\\__,_|\\___|_|\\___/ \\___|",x, y+(6*spacing),LIGHTRED,LARGE_FONT);
}


void drawSelector(int x, int y, char color, int size){
	write_char(42, x, y, color, size);
}

void drawMenu(int targetWidth, int targetHeight){
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;

	drawScreenBorders(targetWidth, targetHeight);
	screenLogo(x+58, y+50, 13);

	write_text("Play Easy", x+208, y+200,LIGHTCYAN,LARGE_FONT);
	write_text("Play Hard", x+208, y+225,LIGHTCYAN,LARGE_FONT);
	write_text("Exit", x+208, y+250,LIGHTCYAN,LARGE_FONT);
}

void drawO(int start_x, int end_x, int start_y, int end_y, int color){
	int x = start_x+20, y = start_y+20;

	write_char(220, start_x+12, start_y+13, color, LARGE_FONT);
	write_char(220, end_x-18, start_y+13, color, LARGE_FONT);

	write_char(220, start_x+12, end_y-12, color, LARGE_FONT);
	write_char(220, start_x+13, end_y-12, color, LARGE_FONT);
	
	while(x < end_x-25){
		write_char(220, x, start_y+5, color, LARGE_FONT);
		write_char(220, x, end_y-5, color, LARGE_FONT);
		x++;
	}

	write_char(220, start_x+13, start_y+13, color, LARGE_FONT);
	write_char(220, end_x-19	, start_y+13, color, LARGE_FONT);

	write_char(220, end_x-18, end_y-12, color, LARGE_FONT);
	write_char(220, end_x-19	, end_y-12, color, LARGE_FONT);
	while(y < end_y-20){
		write_char(220, start_x+5, y, color, LARGE_FONT);
		write_char(220, end_x-10, y, color, LARGE_FONT);
		y++;
	}


}


void drawX(int start_x, int end_x, int start_y, int end_y, int color){
	int x = end_x-10, y = start_y+5;
	while(x > start_x+5){
		while(y < end_y-5){
			write_char(220, x, y, color, LARGE_FONT);
			y++;
   			x--;
		}
   		x--;

	}

	x = start_x+5;
	y = start_y+5;	

	while(x < end_x-5){
		while(y < end_y-5){
			write_char(220, x, y, color, LARGE_FONT);
			y++;
   			x++;
		}
   		x++;
	}
}


void drawMove(int board[], int index, int clear_boolean, int size){
	int targetHeight = 300;
	int targetWidth = 300;
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;
	int increment_x = targetWidth/3;
	int increment_y = targetWidth/3;

	int x1, y1, x2, y2;
	switch(index){
		case 0:
			x1 = x+7, x2 = (x+increment_x)-3;
			y1 = y+8, y2 = y+increment_y-8;
			TILE1_X = (x1+x2)/2, TILE1_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);

			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1) tempcolor = BLACK;
				else tempcolor = LIGHTCYAN;
				write_char(91, TILE1_X-10, TILE1_Y, tempcolor, size);
				write_char(49, TILE1_X, TILE1_Y, tempcolor, size);
				write_char(93, TILE1_X+10	, TILE1_Y, tempcolor, size);
			}
			break;
		case 1:
			x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
			y1 = y+8, y2 = y+increment_y-8;
			TILE2_X = (x1+x2)/2, TILE2_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE2_X-10, TILE2_Y, tempcolor, size);
				write_char(50, TILE2_X, TILE2_Y, tempcolor, size);
				write_char(93, TILE2_X+10	, TILE2_Y, tempcolor, size);
			}
			break;
		case 2:
			x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
			y1 = y+8, y2 = y+increment_y-8;
			TILE3_X = (x1+x2)/2, TILE3_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE3_X-10, TILE3_Y, tempcolor, size);
				write_char(51, TILE3_X, TILE3_Y, tempcolor, size);
				write_char(93, TILE3_X+10	, TILE3_Y, tempcolor, size);
			}
			break;
		case 3:
			x1 = x+7, x2 = (x+increment_x)-3;
			y1 = y+increment_y+8, y2 = y+(increment_y*2)-6;
			TILE4_X = (x1+x2)/2, TILE4_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE4_X-10, TILE4_Y, tempcolor, size);
				write_char(52, TILE4_X, TILE4_Y, tempcolor, size);
				write_char(93, TILE4_X+10	, TILE4_Y, tempcolor, size);
			}
			break;
		case 4:
			x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
			y1 = y+increment_y+8, y2 = y+(increment_y*2)-6;
			TILE5_X = (x1+x2)/2, TILE5_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE5_X-10, TILE5_Y, tempcolor, size);
				write_char(53, TILE5_X, TILE5_Y, tempcolor, size);
				write_char(93, TILE5_X+10	, TILE5_Y, tempcolor, size);
			}
			break;
		case 5:
			x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
			y1 = y+increment_y+8, y2 = y+(increment_y*2)-6;
			TILE6_X = (x1+x2)/2, TILE6_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE6_X-10, TILE6_Y, tempcolor, size);
				write_char(54, TILE6_X, TILE6_Y, tempcolor, size);
				write_char(93, TILE6_X+10	, TILE6_Y, tempcolor, size);
			}
			break;
		case 6:
			x1 = x+7, x2 = (x+increment_x)-3;
			y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-6;
			TILE7_X = (x1+x2)/2, TILE7_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE7_X-10, TILE7_Y, tempcolor, size);
				write_char(55, TILE7_X, TILE7_Y, tempcolor, size);
				write_char(93, TILE7_X+10	, TILE7_Y, tempcolor, size);
			}
			break;
		case 7:
			x1 = x+increment_x+7, x2 = x+(increment_x*2)-3;
			y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-6;
			TILE8_X = (x1+x2)/2, TILE8_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE8_X-10, TILE8_Y, tempcolor, size);
				write_char(56, TILE8_X, TILE8_Y, tempcolor, size);
				write_char(93, TILE8_X+10	, TILE8_Y, tempcolor, size);
			}
			break;
		case 8:
			x1 = x+(increment_x*2)+7, x2 = x+(increment_x*3)-3;
			y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-6;
			TILE9_X = (x1+x2)/2, TILE9_Y = (y1+y2)/2;

			if(board[index] == -1){ //Draw O
				drawO(x1, x2, y1, y2, CYAN);
			}
			else if(board[index] == 1){ //Draw X
				drawX(x1, x2, y1, y2, LIGHTRED);
			}
			else{
				int tempcolor;
				if(clear_boolean != 1){ 
					tempcolor = BLACK;
				}
				else{ 
					tempcolor = LIGHTCYAN;
				}
				write_char(91, TILE9_X-10, TILE9_Y, tempcolor, size);
				write_char(57, TILE9_X, TILE9_Y, tempcolor, size);
				write_char(93, TILE9_X+10	, TILE9_Y, tempcolor, size);
			}
			break;

	}
}

void reprintMoves(int board[], int clear_boolean){
	drawMove(board, 0, clear_boolean, LARGE_FONT); //First Tile
	drawMove(board, 1, clear_boolean, LARGE_FONT); //Second Tile
	drawMove(board, 2, clear_boolean, LARGE_FONT); //Third Tile

	drawMove(board, 3, clear_boolean, LARGE_FONT); //Fourth Tile
	drawMove(board, 4, clear_boolean, LARGE_FONT); //Fifth Tile
	drawMove(board, 5, clear_boolean, LARGE_FONT); //Sixth Tile

	drawMove(board, 6, clear_boolean, LARGE_FONT); //Seventh Tile
	drawMove(board, 7, clear_boolean, LARGE_FONT); //Eight Tile
	drawMove(board, 8, clear_boolean, LARGE_FONT); //Nine Tile
}

void drawTile(int start_x1, int end_x1, int start_x2, int end_x2, int start_x3, int end_x3, int start_y, int end_y, int color){
	while(start_y < end_y){
		int x1 = start_x1, x2 = start_x2, x3 = start_x3;
		while(x1 < end_x1 && x2 < end_x2 && x3 < end_x3){
	   		write_char(220, x1, start_y, color, LARGE_FONT);
	   		write_char(220, x2, start_y, color, LARGE_FONT);
	   		write_char(220, x3, start_y, color, LARGE_FONT);
			x1+=5;
			x2+=5;
			x3+=5;
		}
		start_y+=5;
	}
}


void drawBoard(int board[], int targetWidth, int targetHeight){
	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;
	int increment_x = targetWidth/3;
	int increment_y = targetWidth/3;

	// Top Border
	drawHorizontalBorder(x, (x+targetWidth)+3, y, DARKGRAY, LARGE_FONT);

	// Left and Right Border
	drawVerticalBorder(x, y+8, y+targetHeight+10, DARKGRAY, LARGE_FONT); //Left Border
	drawVerticalBorder(x+targetWidth, y+8, y+targetHeight+10, DARKGRAY, LARGE_FONT); //Right Border

	// Bottom Border
	drawHorizontalBorder(x, (x+targetWidth), y+targetHeight, DARKGRAY, LARGE_FONT);

	// Vertical Grid
	drawVerticalBorder(x+increment_x, y+8, y+targetHeight+10, DARKGRAY, LARGE_FONT);
	drawVerticalBorder(x+(increment_x*2), y+8, y+targetHeight+10, DARKGRAY, LARGE_FONT);
	drawVerticalBorder(x+(increment_x*3), y+8, y+targetHeight+10, DARKGRAY, LARGE_FONT);

	// Horizontal Grid
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*1), DARKGRAY, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*2), DARKGRAY, LARGE_FONT);
	drawHorizontalBorder(x+7, (x+targetWidth)-2, y+(increment_y*3), DARKGRAY, LARGE_FONT);

	/*First Tile*/
	int x1 = x+7, x2 = (x+increment_x)-3;
	int y1 = y+8, y2 = y+increment_y-6;
	TILE1_X = (x1+x2)/2, TILE1_Y = (y1+y2)/2;
	// drawTile(x1, x2, y1, y2, LIGHTCYAN);
	// drawX(x1, x2, y1, y2, LIGHTRED);

	/*Second Tile*/
	int x3 = x+increment_x+7, x4 = x+(increment_x*2)-3;
	y1 = y+8, y2 = y+increment_y-6;
	TILE2_X = (x3+x4)/2, TILE2_Y = (y1+y2)/2;
	// drawTile(x3, x4, y1, y2, LIGHTCYAN);
	// drawO(x1, x2, y1, y2, CYAN);



	/*Third Tile*/
	int x5 = x+(increment_x*2)+7, x6 = x+(increment_x*3)-3;
	y1 = y+8, y2 = y+increment_y-6;
	TILE3_X = (x5+x6)/2, TILE3_Y = (y1+y2)/2;
	drawTile(x1, x2, x3, x4, x5, x6, y1, y2, LIGHTCYAN);
	// drawX(x1, x2, y1, y2, LIGHTRED);


	/*Fourth Tile*/
	x1 = x+7, x2 = (x+increment_x)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-6;
	TILE4_X = (x1+x2)/2, TILE4_Y = (y1+y2)/2;
	// drawTile(x1, x2, y1, y2, LIGHTCYAN);
	// drawO(x1, x2, y1, y2, CYAN);

	/*Fifth Tile*/
	x3 = x+increment_x+7, x4 = x+(increment_x*2)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-6;
	TILE5_X = (x3+x4)/2, TILE5_Y = (y1+y2)/2;
	// drawTile(x1, x2, y1, y2, LIGHTCYAN);

	/*Sixth Tile*/
	x5 = x+(increment_x*2)+7, x6 = x+(increment_x*3)-3;
	y1 = y+increment_y+8, y2 = y+(increment_y*2)-6;
	TILE6_X = (x5+x6)/2, TILE6_Y = (y1+y2)/2;
	drawTile(x1, x2, x3, x4, x5, x6, y1, y2, LIGHTCYAN);

	// drawTile(x1, x2, y1, y2, LIGHTCYAN);
	// drawO(x1, x2, y1, y2, CYAN);

	/*Seventh Tile*/
	x1 = x+7, x2 = (x+increment_x)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-6;
	TILE7_X = (x1+x2)/2, TILE7_Y = (y1+y2)/2;
	// drawTile(x1, x2, y1, y2, LIGHTCYAN);
	// drawX(x1, x2, y1, y2, LIGHTRED);

	/*Eighth Tile*/
	x3 = x+increment_x+7, x4	 = x+(increment_x*2)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-6;
	TILE8_X = (x3+x4	)/2, TILE8_Y = (y1+y2)/2;
	// drawTile(x1, x2, y1, y2, LIGHTCYAN);
	// drawO(x1, x2, y1, y2, CYAN);


	/*Ninth Tile*/
	x5 = x+(increment_x*2)+7, x6 = x+(increment_x*3)-3;
	y1 = y+(increment_y*2)+8, y2 = y+(increment_y*3)-6;
	TILE9_X = (x5+x6)/2, TILE9_Y = (y1+y2)/2;
	// drawTile(x1, x2, y1, y2, LIGHTCYAN);
	// drawX(x1, x2, y1, y2, LIGHTRED);

	drawTile(x1, x2, x3, x4, x5, x6, y1, y2, LIGHTCYAN);


	reprintMoves(board, 0);
}

