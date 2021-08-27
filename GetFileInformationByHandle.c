#include <Windows.h>
#include "Util.h"

#define FILENAME "Files\\Constants.txt"

int main() {
	BY_HANDLE_FILE_INFORMATION* Info;
	SYSTEMTIME* Time;
	HANDLE Handle = CreateFile(
		FILENAME,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	
	GetFileInformationByHandle(
		Handle,
		Info
	);
	
	FileTimeToSystemTime(&Info->ftCreationTime, Time);
	printf("Filesize -> %d bytes\nCreated at %lu:%lu:%lu\n", Info->nFileSizeLow, Time->wHour, Time->wMinute, Time->wSecond);
	CloseHandle(Handle);
	return 0;
}
