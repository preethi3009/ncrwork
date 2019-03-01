#include<stdio.h>
#include<windows.h>
#include<tchar.h>

DWORD WINAPI  primaryThreadFun(LPVOID lpParameter);
DWORD WINAPI  secondaryThreadFun(LPVOID lpParameter);


int main(int argc, TCHAR *argv[])
{
	HANDLE hPrimaryThread;
	DWORD dwPrimaryThreadId;

	//creating a thread
	hPrimaryThread = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		primaryThreadFun,  //lpStartAddress
		NULL, //lpParameter
		0,         //dwCreationFlags
		&dwPrimaryThreadId     //lpThreadId
	);

	//checking whether thread is created or not
	if (NULL == hPrimaryThread)
	{
		printf(" primary thread creation unsuccessfull: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf(" primary thread created successfully\n");
	}

	//waiting for thread to execute
	printf("parent waiting for primary thread to execute..\n\n");
	WaitForSingleObject(
		hPrimaryThread, //hHandle
		INFINITE  //dwMilliseconds
	);

	
	return 0;
}


//thread function for primary thread
DWORD WINAPI  primaryThreadFun(LPVOID lpParameter)
{
	printf("In primary thread\n");
	HANDLE hSecondaryThread;
	DWORD dwSecondaryThreadId;
	DWORD  dwExitCode;//exit code variable

	//creating a thread
	hSecondaryThread = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		secondaryThreadFun,  //lpStartAddress
		NULL, //lpParameter
		0,         //dwCreationFlags
		&dwSecondaryThreadId     //lpThreadId
	);

	//checking whether thread is created or not
	if (NULL == hSecondaryThread)
	{
		printf("secondary thread creation unsuccessfull: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("secondary thread created successfully\n");
	}

	//waiting for thread to execute
	printf("Primary thread waiting for Secondary thread to execute..\n\n");
	WaitForSingleObject(
		hSecondaryThread, //hHandle
		INFINITE  //dwMilliseconds
	);

	//getting exit code from the thread_fun
	BOOL retGetexitcodethread = GetExitCodeThread(
		hSecondaryThread,//thread handle
		&dwExitCode //pointer to exitcode
	);

	if (0 == retGetexitcodethread)
	{
		_tprintf(_T("GetExitCodeThread: error(%d)"), GetLastError());
		return FALSE;
	}
	else
	{
		//terminating the thread
		BOOL ret = TerminateThread(
			hSecondaryThread, //handle Thread
			dwExitCode  //dwExitCode
		);

		//checking for thread termination
		if (0 == ret)
			printf("Secondary thread not terminated\n");
		else
			printf("Secondary thread terminated with exit code (%d)\n", dwExitCode);
	}

	return 0;
}

DWORD WINAPI  secondaryThreadFun(LPVOID lpParameter)
{
	printf("In secondary thread\n");
	for (int i = 0; i <= 5; i++)j
	{
		printf("(%d)\n", i);
		Sleep(500);
	}
	return 0;
}