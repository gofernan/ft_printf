#include <stdio.h>
#include <locale.h>

int main(void)
{
	//setlocale(LC_ALL, "");
	char *loc = setlocale(LC_CTYPE, NULL);
	//printf("%C", L'狼');
	printf("%s\n", loc);
	return (0);
}
