#include <windows.h>
#include <tchar.h>
#include <stdio.h>

const wchar_t *envVarString = L"%TEMP%";
#define INFO_BUFFER_SIZE 32767

int main()
{
	TCHAR  infoBuf[INFO_BUFFER_SIZE];
	DWORD  bufCharCount = INFO_BUFFER_SIZE;
	bufCharCount = ExpandEnvironmentStrings(envVarString, infoBuf,
		INFO_BUFFER_SIZE);
	if (bufCharCount > INFO_BUFFER_SIZE)
		_tprintf(TEXT("\n\t(Buffer too small to expand: \"%s\")"),
			envVarString);
	else if (!bufCharCount)
		printf("Error is :%d ", GetLastError());
	else
		_tprintf(TEXT("\n%s"), infoBuf);
	return 0;
}

