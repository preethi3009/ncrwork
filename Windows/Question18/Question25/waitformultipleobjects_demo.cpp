//Write a program to create two threads and print the reason for
//WaitForMultipleObjects return.
//Print results with.
//a. bWaitAll = TRUE and timeout interval INFINITE
//b. bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000)
//c. bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)
//d. bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000)



#include<stdio.h>
#include<windows.h>
#include<tchar.h>

//thread function 1
DWORD WINAPI  thread_fun1(LPVOID lpParameter)
{
	_tprintf(_T("In thread function 1\n"));
	Sleep(4000);
	//Sleep(2000);
	return 0;
}

//thread function 2
DWORD WINAPI  thread_fun2(LPVOID lpParameter)
{
	_tprintf(_T("In thread function 2\n"));
	Sleep(3000);
		return 0;
}


int main(int argc, TCHAR *argv[])
{
	HANDLE hThread1, hThread2;
	DWORD dwThreadId1,dwThreadId2;
	HANDLE arr_handle[2];
	int choice;

	printf("enter your choice \n");
	printf("a. bWaitAll = TRUE and timeout interval INFINITE\nb. bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000)\nc. bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)\nd. bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000)");
	scanf("%d", &i);
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

	DWORD d;

	switch (choice)
	{
	case '1':
	{//bWaitAll = TRUE and timeout interval INFINITE
		d = WaitForMultipleObjects(
			2,//no of handles
			arr_handle,//lpHAndles
			TRUE,//wait for all threads to get signalled
			INFINITE//dwMIlliseconds
		);
		break;
	}
	case '2': {
		//bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000) 
		d = WaitForMultipleObjects(2, arr_handle, FALSE, INFINITE);
		break;
	}
	case '3':
	{//bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)  
		d = WaitForMultipleObjects(2, arr_handle, FALSE, INFINITE);
		break;
	}
	case '4':
	{
		//bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000)
		d=WaitForMultipleObjects(2, arr_handle, FALSE,	2000);
		break;
	}
	}
	switch (d)
	{
	case WAIT_OBJECT_0 + 0:
	{printf("thread 1 signaled\n");
	break;
	}
	case WAIT_OBJECT_0 + 1:
	{	printf("thread2 signaled\n");
	break;
	}
	case WAIT_TIMEOUT:
	{	printf("timeout elapsed\n");
	break;
	}
	default:printf("error:(%d)", GetLastError());
		break;
	}

	return 0;
}
