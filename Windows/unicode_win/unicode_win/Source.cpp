#include<stdio.h>
#include<Windows.h>

int main()
{
	CHAR ansi_char='A';//ANSI character
	WCHAR word_char = L'A';//Word character

	CHAR ansi_arr[] = "ANSI";//ANSI array
	WCHAR word_arr[] = L"WORD";//Word array
	
	BOOL ret;
	int size;

	//checking whether ansi_arr is unicode or not
	ret = IsTextUnicode(ansi_arr,strlen(ansi_arr),NULL );
	
	if (ret)
		printf("%s is unicode\n",ansi_arr);
	
	else
		printf("%s is not unicode\n",ansi_arr);

	//checking whether word_arr is Unicode or not
	ret = IsTextUnicode(word_arr, wcslen(word_arr), NULL);
	
	if (ret)
		printf("%S is unicode\n",word_arr);
	
	else
		printf("%S is not unicode\n",word_arr);

	//multibyte to widechar
	size = MultiByteToWideChar(CP_UTF8, 0, ansi_arr, -1, NULL, 0);
	
	wchar_t *wstr = new wchar_t[size];
	
	MultiByteToWideChar(CP_UTF8, 0, ansi_arr, -1, wstr, size);
	
	printf("After multibyte to wide char conversion\n");
	
	//checking after conversion
	ret = IsTextUnicode(wstr, wcslen(wstr), NULL);
	
	if (ret)
		printf("%S is unicode\n",wstr);
	
	else
		printf("%s is not unicode\n",wstr);
	
	//widechar to multibyte
	size = WideCharToMultiByte(CP_UTF8, 0,word_arr,-1,NULL,0 ,NULL,NULL);
	
	char *astr = new char[size];
	
	WideCharToMultiByte(CP_UTF8, 0, word_arr, -1, astr, size, NULL, NULL);
	
	printf("After widechar to multibyte conversion\n");
	
	//checking after conversion
	ret = IsTextUnicode(astr, strlen(astr), NULL);
	
	if (ret)
		printf("%s is unicode\n",astr);
	
	else
		printf("%s is not unicode\n",astr);

	//getlasterror
	
	ret=MultiByteToWideChar(CP_UTF8, 0, 0, -1, NULL, 0);
	if (ret == 0)
	{
		printf("Error no:%d", GetLastError());
		return -1;
	}
	return 0;

}