#include "Batchim.h"

wchar_t *AnsiToUni(char *ansi)
{
	wchar_t temp[80];
	wchar_t *uni;
	int size;

	size = MultiByteToWideChar(CP_ACP, 0, ansi, strlen(ansi), temp, sizeof(temp));
	temp[size] = 0;

	uni = (wchar_t *)malloc((size_t)size);
	wcscpy(uni, temp);
	return uni;
}

int batchim(char *str){
	wchar_t *temp = AnsiToUni(str);
	wchar_t hangul = temp[wcslen(temp) - 1];
	hangul -= 0xAC00;
	wchar_t jong = hangul % 28;

	return jong;
}

char *eun(int batchim)
{
	if (batchim == 0){
		return "´Â";
	}
	else {
		return "Àº";
	}
}