#include <stdio.h>
#include <locale.h>
int main(void)
{
//	setlocale(LC_NUMERIC, "en_US.UTF-8");
	int a = -456;
	long b = 23423;

	//printf("%-+.4dhola", a);
	printf("% d", a);
	//printf("%'d", a);
	return (0);
}
