//9. Write a program to create a child process.
//Use GetCurrentProcessId, GetCurrentThreadId, GetProcessId, GetThreadId, GetProcessIdOfThread
//to print process and thread information in each of the process.

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	BOOL bReturn;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (argc != 2)
	{
		printf("Invalid number of arguments\n");
		return -1; 
	}

	// Start the child process 1. 
	bReturn = CreateProcess(NULL,			// No module name (use command line)
							argv[1],        // Command line
							NULL,           // Process handle not inheritable
							NULL,           // Thread handle not inheritable
							FALSE,          // Set handle inheritance to FALSE
							0,              // No creation flags
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
	{
		printf(" child process created successfully\n");
		printf("child process id (%d)\n", GetProcessId(pi.hProcess));
		printf("thread id (%d)\n", GetThreadId(pi.hThread));
		printf("process id of thread (%d)\n",GetProcessIdOfThread(pi.hThread));
	}

	//closing process handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);

	printf("current process id - %d\n", GetCurrentProcessId());
	printf("current thread id - %d\n\n", GetCurrentThreadId());
	
}
