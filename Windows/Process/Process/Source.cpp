//program which uses the API “CreateProcess” to create two child processes(say calc.exe and notepad.exe).
//Print handle and process Id of each child process.

#include <windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(int argc, TCHAR *argv[])
{
	STARTUPINFO si1,si2;//instances of STARTUPINFO structure
	PROCESS_INFORMATION pi1,pi2;//instances of PROCESS_INFORMATION structure
	BOOL bReturnp1,bReturnp2;//retrun values of process creation

	//filling blocks of memory with zeroes
	ZeroMemory(&si1, sizeof(si1));
	si1.cb = sizeof(si1);
	ZeroMemory(&pi1, sizeof(pi1));

	ZeroMemory(&si2, sizeof(si2));
	si2.cb = sizeof(si2);
	ZeroMemory(&pi2, sizeof(pi2));

	//checking for valid no of arguments
	if (argc != 3)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}

	// Start the child process 1. 
	bReturnp1=CreateProcess(NULL,			// No module name (use command line)
							argv[1],        // Command line
							NULL,           // Process handle not inheritable
							NULL,           // Thread handle not inheritable
							FALSE,          // Set handle inheritance to FALSE
							0,              // No creation flags
							NULL,           // Use parent's environment block
							NULL,           // Use parent's starting directory 
							&si1,           // Pointer to STARTUPINFO structure
							&pi1           // Pointer to PROCESS_INFORMATION structure
						);

	//if CreateProcess fails
	if (0 == bReturnp1)
	{
		printf("CreateProcess failed (%d).\n", GetLastError());
		return;
	}
	else
	{
		printf("process 1 created successfully\n");
		printf("process id (%d)\n", GetProcessId(pi1.hProcess));
		printf("handle : (%d)\n\n", pi1.hProcess);
	}

	//closing process handles
	CloseHandle(pi1.hProcess);
	CloseHandle(pi1.hThread);

	// Start the child process 2. 
	bReturnp2 = CreateProcess(	NULL,			// No module name (use command line)
								argv[2],        // Command line
								NULL,           // Process handle not inheritable
								NULL,           // Thread handle not inheritable
								FALSE,          // Set handle inheritance to FALSE
								0,              // No creation flags
								NULL,           // Use parent's environment block
								NULL,           // Use parent's starting directory 
								&si2,           // Pointer to STARTUPINFO structure
								&pi2           // Pointer to PROCESS_INFORMATION structure
							);

	//if CreateProcess fails
	if (0 == bReturnp2)
	{
		printf("CreateProcess2 failed (%d).\n", GetLastError());
		return;
	}
	else
	{
		printf("process 2 created successfully\n");
		printf("process id (%d)\n", GetProcessId(pi2.hProcess));
		printf("handle : (%d)\n\n", pi2.hProcess);
	}

	// Close process and thread handles. 
	CloseHandle(pi2.hProcess);
	CloseHandle(pi2.hThread);

}