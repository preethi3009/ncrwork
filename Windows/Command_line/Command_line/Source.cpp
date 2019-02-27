#include<stdio.h>
#include<Windows.h>

int main(int argc, char **argv)
{
	LPWSTR *arglist;
	int nargs;
	int i;
	arglist = CommandLineToArgvW(GetCommandLine(), &nargs);
	if (NULL == arglist)
	{
		wprintf(L"CommandLineToArgvW failed\n");
		return 0;
	}
	for (i = 0; i < nargs; i++)
		printf("%d:%ws\n", i, arglist[i]);
	return 0;
}