#include<stdio.h>
#include<windows.h>
#include<tchar.h>

long g_x=0;

//thread function 1
DWORD WINAPI  thread_fun1(LPVOID lpParameter)
{
	_tprintf(_T("In thread function 1\n"));
	g_x++;
	printf("shared variable = %d\n\n",g_x);
	return 0;
}

//thread function 2
DWORD WINAPI  thread_fun2(LPVOID lpParameter)
{
	_tprintf(_T("In thread function 2\n"));
	g_x++;
	printf("shared variable = %d\n\n", g_x);
	return 0;
}


int main(int argc, TCHAR *argv[])
{
	HANDLE hThread1,hThread2;
	DWORD dwThreadId1,dwThreadId2;

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
			&dwThreadId1     //lpThreadId
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
		
		//waiting for threads to execute
		printf("waiting..\n\n");
		getchar();
		
		printf("Main process\nshared variable = %d", g_x);

	return 0;
	}
