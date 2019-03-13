
//5.Write a program to create a new file with CreateFile and use WriteFile to write text to file.
//Verify the written text by manually opening file in notepad / wordpad etc

#include<stdio.h>
#include<Windows.h>
#include<tchar.h>

int _tmain(int argc, TCHAR *argv[])
{
	HANDLE hFile;//handle to the file
	DWORD dwnbw=0;//no of bytes to write
	WCHAR tBuffer[] = L"SAMPLE CONTENT TO THE FILE";// buffer that receives the data read from the file

	//creating handle to the file
	hFile = CreateFile(argv[1],//filename passed as argument
		GENERIC_WRITE,//access to the file
		0,	//file cannot be shared
		NULL,//security attribute 
		CREATE_ALWAYS,//create always
		FILE_ATTRIBUTE_NORMAL,//flags and attributes
		NULL//template file
	);

	//if createfile fails
	if (INVALID_HANDLE_VALUE == hFile)
		_tprintf(_T("error :(%d)"), GetLastError());

	//printing filename that is passed as argument
	else
		_tprintf(_T("File creation sucessfull : %s\n"), argv[1]);

	//reaading the file and printing the contents to the console
	BOOL ret = WriteFile(	hFile,//handle to the file
							tBuffer,// buffer containing the data to be written to the file
							sizeof(tBuffer),//no of bytes to write
							&dwnbw,//no of bytes written
							NULL//pointer to an overlapped structure
	);

	if(FALSE == ret)
	{
		_tprintf(_T("Unable to write to file. error:(%d)\n"),GetLastError());
	}
	else
	{
		_tprintf(TEXT("Wrote to %s successfully.\n"),argv[1]);
	}
	
	//closing the handle to the file
	CloseHandle(hFile);

	return 0;
}