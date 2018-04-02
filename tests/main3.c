#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <string.h>

int main(void)
{
	setlocale(LC_ALL, "");
	char string[4]={ 0x61, 0x81, 0x61, 0 };
	wchar_t mya = L'诶';
	wchar_t *mystring = L"诶Hello how are you?";

	printf("my str is: %s", string);
	printf("mya is: %lc\n", mya);
	printf("my string %ls\n", mystring);
	printf("len %lu\n", wcslen(mystring));
	printf("诶诶诶诶诶诶诶\n");

	return (0);
}
