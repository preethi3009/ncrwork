//Write a program to modify shared variable between two threads guarded by critical section.
//Use InitializeCriticalSection or InitializeCriticalSectionAndSpinCount, DeleteCriticalSection, EnterCriticalSection, LeaveCriticalSection.
//Wait for both the threads to exit before exiting process primary thread.

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int shared_sum = 0;
CRITICAL_SECTION cs;

DWORD WINAPI thread_fun1(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	for (int i = 0; i < 10; i++)
		printf("thread 1 sum val is %d\n",shared_sum += 1);
	LeaveCriticalSection(&cs);
	return 0;
}

DWORD WINAPI thread_fun2(LPVOID lpParameter)
{
	EnterCriticalSection(&cs);
	shared_sum = 0;
	for (int i = 0; i < 10; i++)
		printf("thread 2 sum val is %d\n",shared_sum += 1);
	LeaveCriticalSection(&cs);
	return 0;
}
int main()
{ 
	HANDLE hThread1, hThread2;
	DWORD dwThreadId1, dwThreadId2;
	HANDLE hArr[2];

	InitializeCriticalSection(&cs);

	hThread1 = CreateThread(NULL, 0, thread_fun1, NULL, 0, &dwThreadId1);
	hThread2 = CreateThread(NULL, 0, thread_fun2, NULL, 0, &dwThreadId2);

	if (INVALID_HANDLE_VALUE == hThread1)
		printf("handle error:(%d)", GetLastError());
	else
		printf("thread 1 created successfully\n");

	if (INVALID_HANDLE_VALUE == hThread2)
		printf("handle error:(%d)", GetLastError());
	else
		printf("thread 2 created successfully\n");
	hArr[0] = hThread1;
	hArr[1] = hThread2;

	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	printf("final sum val is %d", shared_sum);

	DeleteCriticalSection(&cs);
	return 0;
}