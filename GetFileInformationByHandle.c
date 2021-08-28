#include <Windows.h>
#include "Util.h"

#define FILENAME "Util.h"

int main() {
	BY_HANDLE_FILE_INFORMATION Info;
	SYSTEMTIME Time;
	
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
		&Info
	);

	if(!FileTimeToSystemTime(&Info.ftCreationTime, &Time)) {
		PERROR(GetLastError());
		return 1;
	}
	
	printf(":: "FILENAME"\n\n");
	printf("Filesize           -> %d bytes\n", Info.nFileSizeLow);
	printf("Created at         -> %.2d/%.2d %.2d:%.2d:%.2d\n", Time.wDay, Time.wMonth, Time.wHour, Time.wMinute, Time.wSecond);
	FileTimeToSystemTime(&Info.ftLastWriteTime, &Time);
	printf("Last write time    -> %.2d/%.2d %.2d:%.2d:%.2d\n", Time.wDay, Time.wMonth, Time.wHour, Time.wMinute, Time.wSecond);
	FileTimeToSystemTime(&Info.ftLastAccessTime, &Time);
	printf("Last access time   -> %.2d/%.2d %.2d:%.2d:%.2d\n", Time.wDay, Time.wMonth, Time.wHour, Time.wMinute, Time.wSecond);
	return 0;
}
