#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Util.h"

#define WORK
#define SLEEP	0		// FUCK i3 5gen
#define LOOP

int main() {
	POINT  Point;
	BYTE   Keys[256];
	char   KBDLayout[128];
	#ifdef LOOP
	while(1) {
		Sleep(SLEEP);
		system("cls");
	#endif
		GetCursorPos(&Point);
		printf(":: Cursor position -> %d, %d\n", Point.x, Point.y);
		#ifdef WORK
		GetKeyState(0);						// I don't even know why we use it before GetKeyboardState ¯\_(ツ )_/¯.
		#endif
		GetKeyboardState(Keys);				// What i know is if we don't use it, it will not work
		
		if(GetKeyboardLayoutName(KBDLayout)) {
		    printf(":: Keyboard Layout -> %s", KBDLayout);
        }
        
		puts("\n-- Keyboard state -- \n");
		int Key = 0;
		for(Key; Key < sizeof Keys; Key++) {
			if(Keys[Key]) printf("%d (%c) -> %d\n", Key, Key, Keys[Key]);
		}
		puts("------------------------\n");
	#ifdef LOOP
	}
	#endif
}
