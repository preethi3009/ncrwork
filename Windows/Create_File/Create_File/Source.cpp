#include<stdio.h>
#include<tchar.h>
#include<Windows.h>
#include<fileapi.h>

#define BUFFSIZE 100
int main(int argc,TCHAR *argv[])
{
	HANDLE hFile;
	DWORD dwnbr;
	TCHAR tBuffer[BUFFSIZE];
	hFile = CreateFile(argv[1], GENERIC_READ, 0, NULL,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,NULL );
	if (INVALID_HANDLE_VALUE == hFile)
		_tprintf(_T("error :(%d)"), GetLastError());
	else
		_tprintf(_T("FILE NAME : %S"), argv[1]);
	return 0;
	ZeroMemory(tBuffer, BUFFSIZE);
	BOOL ret = ReadFile(hFile, tBuffer, BUFFSIZE, &dwnbr, NULL);
	if (ret == 0)
		printf("cant read file\n");
}