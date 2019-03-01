#include<stdio.h>
#include<windows.h>
#include<tchar.h>



DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	for (int i = 0; i < 10; i++)
	{
		printf("i:(%d)\n", i);
		if (5 == i)
			return i;
		Sleep(1000);
	}
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread;
	DWORD dwThreadId;
	DWORD  dwExitCode;
	LPDWORD lpExitCode;
	hThread=  CreateThread(
		NULL,   //lpThreadAttributes
		0,                  //dwStackSize
		thread_fun,  //lpStartAddress
		NULL, //lpParameter
		0,                   //dwCreationFlags
		&dwThreadId                 //lpThreadId
	);

	if (NULL == hThread)
	{
		printf("thread creation unsuccessfull: error(%d)\n",GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread created successfully\n");

	}
	
	printf("parent waiting for thread to execute..\n");
	 WaitForSingleObject(
		hThread, //hHandle
		INFINITE  //dwMilliseconds
	 );

	 BOOL ret1 = GetExitCodeThread(
		 hThread,//thread handle
		 &dwExitCode //pointer to exitcode
	 );

	 BOOL ret = TerminateThread(
		 hThread, //handle Thread
		 dwExitCode  //dwExitCode
	 );
	 if (0 == ret)
		 printf("thread not terminated\n");
	 else
		 printf("thread terminated with exit code (%d)\n",dwExitCode);
	return 0;
}