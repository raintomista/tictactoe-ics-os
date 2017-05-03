#include "../../sdk/dexsdk.h"
#include "../../sdk/time.h"
#include "graphics.h"
#include "bot.h"
#include "gamelogic.h"

int main(){
	int choice = 0;
	int cur_x=7, cur_y=1, input;

	set_graphics(VGA_640X480X16);

	do{
		clrscr();
		drawMenu(500, 375);

		input = getchar();
		switch(input){
			case KEY_UP:
				cur_x = (cur_x-1) < 7 ? 9 : (cur_x-1);	
				break;
			case KEY_DOWN:
				cur_x = (cur_x+1) > 9 ? 7 : (cur_x+1);	
				break;
			case KEY_SPACE:
				select(cur_x, &choice);
				break;
			default:
				break;
		}
		
	}while(choice != 3);
	
	return 0;
}