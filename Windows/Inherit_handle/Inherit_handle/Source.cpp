#include<stdio.h>
#include<Windows.h>
#include<tchar.h>


int _tmain(int argc, LPWSTR argv[])
{
	HANDLE hFile;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	BOOL bReturn;
	SECURITY_ATTRIBUTES sa;

	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.bInheritHandle = TRUE;
	sa.lpSecurityDescriptor = NULL;

	hFile = CreateFile(L"file.txt", GENERIC_ALL, 0,&sa,CREATE_ALWAYS,0,NULL );

	if (INVALID_HANDLE_VALUE == hFile)
		printf("creation file unsuccess\n %d ",GetLastError());

	//filling blocks of memory with zeroes
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));



	bReturn = CreateProcess(L"C://Users//Ravi kumar Kesari//Source//Repos//preethi3009//ncrwork//Windows//Create_File//Debug//Create_File.exe",			// No module name (use command line)
		(LPWSTR)&hFile,        // Command line
		&sa,           // Process handle not inheritable
		&sa,           // Thread handle not inheritable
		TRUE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory 
		&si,           // Pointer to STARTUPINFO structure
		&pi           // Pointer to PROCESS_INFORMATION structure
	);
	if (0 == bReturn)
	{
		printf("process creation failed : error (%d)", GetLastError());
		return -1;
	}
	else
	{
		printf("creation of process is successfull\n");
		printf("handle of the child process - %d", pi.hProcess);
	}

	printf("handle in the parent process - %d", hFile);
	return 0;
}
