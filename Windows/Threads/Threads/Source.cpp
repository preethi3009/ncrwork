#include<stdio.h>
#include<windows.h>
#include<tchar.h>


//thread function for printing 5 values
DWORD WINAPI  thread_fun(LPVOID lpParameter)
{
	_tprintf(_T("In thread function"));
	for (int i = 0; i < 10; i++)
	{
		printf("i:(%d)\n", i);
		if (5 == i)
			return i;//exiting with i value
		Sleep(1000);//thread sleep for 1 sec
	}
	return 0;
}

int main(int argc, TCHAR *argv[])
{
	HANDLE hThread;
	DWORD dwThreadId;
	DWORD  dwExitCode;//exit code variable

	//creating a thread
	hThread=  CreateThread(
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
		printf("thread creation unsuccessfull: error(%d)\n",GetLastError());
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

	 //getting exit code from the thread_fun
	 BOOL retGetexitcodethread = GetExitCodeThread(
		 hThread,//thread handle
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
			 hThread, //handle Thread
			 dwExitCode  //dwExitCode
		 );

		 //checking for thread termination
		 if (0 == ret)
			 printf("thread not terminated\n");
		 else
			 printf("thread terminated with exit code (%d)\n", dwExitCode);
	 }

	return 0;
}