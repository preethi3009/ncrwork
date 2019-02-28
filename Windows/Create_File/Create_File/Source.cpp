//4. Write a program to open an existing file with CreateFile and use ReadFile
//to read the contents of file till EOF and print the contents to console


#include<stdio.h>
#include<tchar.h>
#include<Windows.h>
#include<fileapi.h>

#define BUFFSIZE 100//size of the  buffer that receives the data read from the file

int _tmain(int argc,TCHAR *argv[])
{
	HANDLE hFile;//handle to the file
	DWORD dwnbr=0;//no of bytes read
	TCHAR tBuffer[BUFFSIZE] = { 0 };// buffer that receives the data read from the file

	//creating handle to the file
	hFile = CreateFile(	argv[1],//filename passed as argument
						GENERIC_READ,//access to the file
						0,	//file cannot be shared
						NULL,//security attribute 
						OPEN_EXISTING,//creation disposition
						FILE_ATTRIBUTE_NORMAL,//flags and attributes
						NULL//template file
					  );
	
	//if createfile fails
	if (INVALID_HANDLE_VALUE == hFile)
		_tprintf(_T("error :(%d)"), GetLastError());

	//printing filename that is passed as argument
	else
		_tprintf(_T("FILE NAME : %s\n"), argv[1]);

	//reaading the file and printing the contents to the console
	BOOL ret = ReadFile(hFile,//handle to the file
						tBuffer,// buffer that receives the data read from the file
						BUFFSIZE,//size of the  buffer that receives the data read from the file
						&dwnbr,//no of bytes read
						NULL//pointer to an overlapped structure
						);

	//if ReadFile fails
	if (0 == ret) {
		_tprintf(_T("Can't read file %s Error:%d"), argv[1], GetLastError());
		return FALSE;
	}

	//printing contents to the console
	else {
		_tprintf(_T("Text from %s is :\n%s"), argv[1], tBuffer);
		return TRUE;
	}

	//closing handle to the file
	CloseHandle(hFile);

	return 0;
}