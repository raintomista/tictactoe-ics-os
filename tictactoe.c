#define WIDTH 640
#define HEIGHT 480
#define TARGET_WIDTH 500
#define TARGET_HEIGHT 375

#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"
#include "graphics.h"
#include "bot.h"
#include "gamelogic.h"


int main(){
	// int choice = 0, selector = 1;
	// int x = ((WIDTH/2)-(TARGET_WIDTH/2))-1;
	// int y = ((HEIGHT/2)-(TARGET_HEIGHT/2))-1;
	// int cur_x=x+190, cur_y=y+200, input;

	// set_graphics(VGA_640X480X16);
	// clrscr();
	// drawMenu(TARGET_WIDTH, TARGET_HEIGHT);
	// drawSelector(cur_x, cur_y, YELLOW, LARGE_FONT);

	// do{
	// 	input = getchar();
	// 	switch(input){
	// 		case KEY_UP:
	// 			drawSelector(cur_x, cur_y, BLACK, LARGE_FONT);
	// 			cur_y = (cur_y-25) < y+200 ? y+250 : (cur_y-25);
	// 			selector = (selector-1) < 1 ? 3 : selector-1;
	// 			drawSelector(cur_x, cur_y, YELLOW, LARGE_FONT);
	// 			break;
	// 		case KEY_DOWN:
	// 			drawSelector(cur_x, cur_y, BLACK, LARGE_FONT);
	// 			cur_y = (cur_y+25) > y+250 ? y+200 : (cur_y+25);
	// 			selector = (selector+1) > 3 ? 1 : selector+1;
	// 			drawSelector(cur_x, cur_y, YELLOW, LARGE_FONT);

	// 			break;
	// 		case KEY_SPACE:
	// 			drawSelector(cur_x, cur_y, BLACK, LARGE_FONT);
	// 			// write_text(" *********",20,20,YELLOW,LARGE_FONT);

	// 			select(selector, &choice);
	// 			break;
	// 	}


		
	// }while(choice != 3)

	startGame(1);
	
	return 0;
}