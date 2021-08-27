#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#define CLEAN(b)(memset(b, 0x0, sizeof b))
#define PINT(n)(printf("%d\n", n))

void PERROR(DWORD CODE);

void PERROR(DWORD Code) {
	char* message;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, 0, Code, 0, (char*)&message, 0, 0);
	printf("Error -> %s\n", message);
}
