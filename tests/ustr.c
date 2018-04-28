#include <stdio.h>
#include <wchar.h>
int main(void)
{
	char a = 0b01000001;
	wchar_t wchar1 = 0x60000000;
	unsigned int int1= 0x60000000;

	printf("value: %d\n", ((a << 1) >> 1));
	printf("value: %x\n", ((wchar1 << 1) >> 1));
	printf("value: %x\n", ((int1 << 1) >> 1));
	return (0);
}
