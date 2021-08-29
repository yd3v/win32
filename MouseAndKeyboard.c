#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include "Util.h"

#define SLEEP 0		// FUCK i3 5gen

int main() {
	POINT Point;
	BYTE Keys[256];
	while(1) {
		Sleep(SLEEP);
		system("cls");
		GetCursorPos(&Point);
		printf("Cursor position -> %d, %d\n", Point.x, Point.y);
		GetKeyState(0);						// I don't even know why we use it before GetKeyboardState ¯\_(ツ )_/¯.
		GetKeyboardState(Keys);				// What i know is if we don't use it, it will not work
		int Key = 0;
		puts("\n-- Keyboard state --\n");
		for(Key; Key < sizeof Keys; Key++) {
			if(Keys[Key]) printf("%d (%c) -> %d\n", Key, Key, Keys[Key]);
		}
	}
}
