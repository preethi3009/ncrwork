#include<stdio.h>
#include<windows.h>
#include<tchar.h>

int _tmain(int argc,TCHAR *argv[])
{
	STARTUPINFO si;//instances of STARTUPINFO structure
	PROCESS_INFORMATION pi;//instances of PROCESS_INFORMATION structure
	BOOL bReturn;//retrun values of process creation

	//filling blocks of memory with zeroes
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	SECURITY_ATTRIBUTES sa;

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	HANDLE hFile;
	hFile = CreateFile(argv[1],//filename passed as argument
		GENERIC_READ,//access to the file
		FILE_SHARE_READ,//file cannot be shared
		&sa,//security attribute 
		CREATE_ALWAYS,//creation disposition
		FILE_ATTRIBUTE_NORMAL,//flags and attributes
		NULL//template file
	);

	//if createfile fails
	if (INVALID_HANDLE_VALUE == hFile)
		_tprintf(_T("error :(%d)"), GetLastError());

	//printing filename that is passed as argument
	else
		_tprintf(_T("FILE NAME : %s\n"), argv[1]);
	
	// Start the child process . 
	bReturn = CreateProcess(L"C://Users//Ravi kumar Kesari//Source//Repos//preethi3009//ncrwork//Windows//Question11//Debug//Question11.exe",			// No module name (use command line)
		(LPTSTR)&hFile,        // Command line
		&sa,           // Process handle not inheritable
		&sa,           // Thread handle not inheritable
		TRUE,          // Set handle inheritance to FALSE
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

		printf("process 1 created successfully\n");

	return 0;
}