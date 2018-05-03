#include <stdio.h>
int main(void)
{
	char a;

	printf("value: %c\n", (a = 2 + 48));
	printf("value: %c\n", (a = (char)2 + '0'));
	return (0);
}
