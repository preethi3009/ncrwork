#include<stdio.h>
#include<windows.h>
#include<tchar.h>


//thread_function for printing 5 values
DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In Thread Function\n"));
	for (int i = 0; i < 10; i++)
	{
		printf("i:(%d)\n", i);
		if (5 == i)
			ExitThread(5);//exiting the thread with exit code 5
		Sleep(1000);
	}
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread;
	DWORD dwThreadId;
	DWORD  dwExitCode;//variable for exit code

	hThread = CreateThread(
							NULL,		   //lpThreadAttributes
							0,			  //dwStackSize
							thread_fun,  //lpStartAddress
							NULL,		//lpParameter
							0,          //dwCreationFlags
							&dwThreadId //lpThreadId
	);

	//if create thread fails
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

	//getting the exit code from thread function
	BOOL ret = GetExitCodeThread(
		hThread,//thread handle
		&dwExitCode //pointer to exitcode
	);

	//printing exitcode value
	printf("thread exited with exit code (%d)\n", dwExitCode);

	return 0;
}