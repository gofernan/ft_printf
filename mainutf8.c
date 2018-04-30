#include "includes/ft_printf.h"
#include <locale.h>
//unsigned char	*utf8conv(unsigned int *wstr);
int main(void)
{
	//setlocale(LC_ALL, "");
	wchar_t *wstr = L"HolaÈȘǊφϞЖԈ";
	//wchar_t *wstr2 = L"ЖԈᆋ";
	//wchar_t *wstr = L"いいえ";
	wchar_t wstr3[4];
	int counter1, counter2;

	wstr3[0] = 254;
	wstr3[1] = 256;
	wstr3[2] = 'b';
	wstr3[3] = '\0';
	char *strtest = "Hello Hello lalala";

	//printf("String es %s\n", utf8conv((unsigned int *)wstr));
	//printf("String es %ls\n", wstr);
	printf("printf working...\n");
	//printf("mb_cur_max: %d", __mb_cur_max);

	//printf("%-32.44ls\n", wstr);
	//ft_printf("%-32.44ls\n", wstr);
	
	/*ft_printf("String s es %s\n", strtest);
	printf("String s es %s\n", strtest);*/
	//ft_printf("String S es %S\n", wstr);
	//printf("String S es %S\n", wstr);
	//ft_printf("String ls es %ls\n", wstr2);
	//printf("String ls es %ls\n", wstr2);
	counter1 = ft_printf("%S", wstr3);
	counter2 = printf("%S", wstr3);
	printf("counter 1:%d, counter 2:%d", counter1, counter2);
	return (0);
}
