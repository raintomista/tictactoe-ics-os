#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"
#include "graphics.h"
#include "bot.h"
#include "gamelogic.h"

int main(){
	int choice = 0;

	int targetWidth = 500;
	int targetHeight = 375;

	int x = ((width/2)-(targetWidth/2))-1;
	int y = ((height/2)-(targetHeight/2))-1;

	int cur_x = x+190, cur_y = y+200, input;

	do{
		clrscr();
		set_graphics(VGA_640X480X16);
		drawMenu(targetWidth, targetHeight);
		write_char(42, cur_x, cur_y, YELLOW, LARGE_FONT);

		input = getch();
		switch(input){
			case KEY_UP:
				cur_y = (cur_y-25) < y+200 ? y+250 : (cur_y-25);	
				break;
			case KEY_DOWN:
				cur_y = (cur_y+25) > y+250 ? y+200 : (cur_y+25);	
				break;
			case KEY_SPACE:
				select(cur_y, &choice);
				break;
			default:
				break;
		}
		
	}while(choice != 3);
	
	return 0;
}