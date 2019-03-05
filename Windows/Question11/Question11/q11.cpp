#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
int _tmain(int argc, TCHAR *argv[])
{
	HANDLE hFile;
	DWORD dwnbw = 0;//no of bytes to write
	WCHAR tBuffer[] = L"sample text to the file";// buffer that receives the data read from the file

	/*printf("hello");
	_tprintf(_T("argv[0] %lu\n"), (unsigned long)*argv[0]);
*/
	BOOL ret = WriteFile(argv[0],//handle to the file
		tBuffer,// buffer containing the data to be written to the file
		sizeof(tBuffer),//no of bytes to write
		&dwnbw,//no of bytes written
		NULL//pointer to an overlapped structure
	);

	if (FALSE == ret)
	{
		_tprintf(_T("Unable to write to file. error:(%d)\n"), GetLastError());
	}
	else
	{
		_tprintf(TEXT("Wrote to %s successfully.\n"), dwnbw, argv[1]);
	}
	return 0;
 }