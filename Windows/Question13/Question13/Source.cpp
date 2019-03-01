#include<stdio.h>
#include<windows.h>
#include<tchar.h>


//thread function for printing 1000 numbers
DWORD WINAPI  thread_fun(LPVOID lpParameter);

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread;
	DWORD dwThreadId;

	//creating a thread
	hThread = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		thread_fun,  //lpStartAddress
		NULL, //lpParameter
		CREATE_SUSPENDED,         //creating thread in suspend state
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

	printf("susupended state...\n");

	Sleep(5000);//parent process sleeps for 5 secs

	//resuming the thread after 5 secs
	printf("resuming the thread....\n");
	DWORD status = ResumeThread(hThread);
	
	//waiting for thread to execute
	printf("parent waiting for thread to execute..\n");
	WaitForSingleObject(
		hThread, //hHandle
		INFINITE  //dwMilliseconds
	);

	return 0;
}

DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n"));
	Sleep(1000);

	for (int i = 1; i <= 1000; i++)
	{
		printf("%d\n", i);//printing 1000 numbers
		Sleep(100);
	}

	return 0;
}