#include <Windows.h>
#include <conio.h>
#include <stdio.h>

int main()
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	printf("Press any key to start WinWord --");
	//_getch();
	char a[29] = "notepad";
	wchar_t wtext[20];
	// Convert to a wchar_t*
	size_t origsize = strlen(a) + 1;
	const size_t newsize = 10;
	size_t convertedChars = 0;
	wchar_t wcstring[newsize];
	mbstowcs_s(&convertedChars, wcstring, origsize, a, _TRUNCATE);
	//LPWSTR  cmd = wtext;
	bool bb = CreateProcess(NULL, wcstring, NULL, NULL, FALSE,0, NULL,NULL, &si, &pi);
	return 0;
}