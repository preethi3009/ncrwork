#include<stdio.h>
#include<windows.h>
#include<tchar.h>


//thread function for printing 5 values
DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n\ng"));
	printf("HELLO WORLD\n");
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread;
	DWORD dwThreadId;
	HANDLE hCurrentprocess = GetCurrentProcess();

	SetPriorityClass(hCurrentprocess, NORMAL_PRIORITY_CLASS);


	//creating a thread
	hThread = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		thread_fun,  //lpStartAddress
		NULL, //lpParameter
		THREAD_PRIORITY_LOWEST,         //dwCreationFlags
		&dwThreadId     //lpThreadId
	);

	//checking whether thread is created or not
	if (NULL == hThread)
	{
		printf("thread creation unsuccessfull: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");
	}

	
	//waiting for thread to execute
	printf("parent waiting for thread to execute..\n");
	WaitForSingleObject(
		hThread, //hHandle
		INFINITE  //dwMilliseconds
	);

	return 0;
}