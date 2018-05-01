#include <stdio.h>
int main(void)
{
	unsigned char str[4];

	str[0] = 0b11110000;
	str[1] = 0b10000000;
	str[2] = 0b10101011;
	str[3] = 0b10111100;

	if ((str[3]) >> 6 != 0x02)
		printf("NO");
	return (0);
}
