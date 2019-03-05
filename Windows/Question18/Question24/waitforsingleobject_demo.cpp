//Write a program to create a thread and print the reason for WaitForSingleObject
//return.Print results with.
//a . timeout interval INFINITE
//b . timeout interval 1000
//c . timeout interval 1000 with Sleep(2000) inside thread

#include<stdio.h>
#include<windows.h>
#include<tchar.h>


//thread function for printing 5 values
DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function\n\n"));
	Sleep(2000);
	printf("HELLO WORLD\n");
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread;
	DWORD dwThreadId;
	DWORD d;

	//creating a thread
	hThread = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		thread_fun,  //lpStartAddress
		NULL, //lpParameter
		0,         //dwCreationFlags
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
	//d=WaitForSingleObject(
	//	hThread, //hHandle
	//	INFINITE  //dwMilliseconds
	//);

	d=WaitForSingleObject(
		hThread, //hHandle
		1000  //dwMilliseconds
	);

	switch (d)
	{
	case WAIT_OBJECT_0:printf("thread terminated\n");
		break;
	case WAIT_TIMEOUT:printf("timeout interval elapsed\n");
		break;
	case WAIT_FAILED:printf("error:(%d)",GetLastError());
		break;
	}
	return 0;
}