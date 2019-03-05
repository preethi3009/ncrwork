//Write a program to increment the value of a shared integer by two threads of the same process.
//Print the final value of shared integer in the process�s primary thread.
//Print the case when final value of shared integer is inconsistent.


#include<stdio.h>
#include<windows.h>
#include<tchar.h>

volatile LONGLONG global_var = 0;

//thread function 1
DWORD WINAPI  thread_fun1(LPVOID lpParameter)
{
	_tprintf(_T("In thread function 1\n"));
	InterlockedIncrement64(&global_var);
	printf("shared variable = %d\n\n", global_var);
	return 0;
}

//thread function 2
DWORD WINAPI  thread_fun2(LPVOID lpParameter)
{
	_tprintf(_T("In thread function 2\n"));
	InterlockedIncrement64(&global_var);
	printf("shared variable = %d\n\n", global_var);
	return 0;
}


int main(int argc, TCHAR *argv[])
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadId1, dwThreadId2;
	HANDLE arr_handle[2];

	//creating threads
	hThread1 = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		thread_fun1,  //lpStartAddress
		NULL, //lpParameter
		0,         //dwCreationFlags
		&dwThreadId1     //lpThreadId
	);

	//checking whether thread is created or not
	if (NULL == hThread1)
	{
		printf("thread 1 creation unsuccessfull: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread 1 created successfully\n\n");
	}

	hThread2 = CreateThread(
		NULL,   //lpThreadAttributes
		0,      //dwStackSize
		thread_fun2,  //lpStartAddress
		NULL, //lpParameter
		0,         //dwCreationFlags
		&dwThreadId2     //lpThreadId
	);

	//checking whether thread is created or not
	if (NULL == hThread2)
	{
		printf("thread 2 creation unsuccessfull: error(%d)\n", GetLastError());
		return FALSE;
	}
	else
	{
		printf("thread 2 created successfully\n\n");
	}

	arr_handle[0] = hThread1;
	arr_handle[1] = hThread2;

	//waiting for threads to execute
	printf("waiting..\n\n");
	WaitForMultipleObjects(
		2,//no of handles
		arr_handle,//lpHAndles
		TRUE,//wait for all threads to get signalled
		INFINITE//dwMIlliseconds
	);

	printf("Main process\nshared variable = %d", global_var);

	return 0;
}
