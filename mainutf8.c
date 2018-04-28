#include "includes/ft_printf.h"
#include <locale.h>
unsigned char	*utf8conv(unsigned int *wstr);
int main(void)
{
	setlocale(LC_ALL, "");
	//wchar_t *wstr = L"HolaÈȘǊφϞЖԈ";
	wchar_t *wstr = L"ЖԈᆋ";


	printf("String es %s\n", utf8conv((unsigned int *)wstr));
	printf("String es %ls\n", wstr);
	return (0);
}
