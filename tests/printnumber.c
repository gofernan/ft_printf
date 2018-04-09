#include <stdio.h>
#include <string.h>

int main(void)
{
	int n = 8;
while (n)
{
	if (n & 1)
		printf("1");
	else
		printf("0");
	n >>= 1;
}
printf("\n");
}
