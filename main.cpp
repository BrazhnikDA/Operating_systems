#include <stdio.h>
#include <Windows.h>

int main()
{
	STARTUPINFO SInf;
	ZeroMemory(&SInf, sizeof(STARTUPINFO));
	PROCESS_INFORMATION PI;
	if (CreateProcess(L"C:/windows/notepad.exe",
		NULL, NULL, NULL, FALSE, 0, NULL, NULL, &SInf, &PI) == TRUE)
	{
		printf("Process ID = %lu\n", PI.dwProcessId);
		if (WaitForSingleObject(PI.hProcess, INFINITE) == FALSE)
		{
			printf("Notepad close\n");
		};
	};
	return 0;
}