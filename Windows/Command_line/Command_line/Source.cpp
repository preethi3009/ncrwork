
//Implement a program where command line arguments passed to program are read
//via GetCommandLine and converted to argv style by CommandLineToArgvW.

#include<stdio.h>
#include<Windows.h>

int main(int argc, char **argv)
{
	LPWSTR *argList;
	int no_of_args;
	int i;

	//getting command line arguments
	argList = CommandLineToArgvW(GetCommandLine(), &no_of_args);
	
	if (NULL == argList)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	
	for (i = 0; i < no_of_args; i++)
		printf("%d:%ws\n", i, argList[i]);
	
	return 0;
}