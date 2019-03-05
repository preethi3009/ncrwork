#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc,TCHAR *argv[]) {

	STARTUPINFO si;// STARTUPINFO structure
	PROCESS_INFORMATION pi;// PROCESS_INFORMATION structure
	BOOL bReturn;//retrun values of process creation

	//filling blocks of memory with zeroes
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	// Start the child process 1. 
	bReturn = CreateProcess(L"C://Users//Ravi kumar Kesari//Source//Repos//preethi3009//ncrwork//Windows//Question16//Debug//Sample.exe",			// No module name (use command line)
		NULL,        // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		TRUE,          // Set handle inheritance to FALSE
		HIGH_PRIORITY_CLASS,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,           // Pointer to STARTUPINFO structure
		&pi           // Pointer to PROCESS_INFORMATION structure
	);

	//if CreateProcess fails
	if (0 == bReturn)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return FALSE;
	}
	else
		printf("process created successfully\n");
	return 0;
}