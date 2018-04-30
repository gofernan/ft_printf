#include <unistd.h>
#include <stdio.h>

int main(void)
{
	unsigned char str[7];

	str[0] = 0b11010000;
	str[1] = 0b10010110;
	str[2] = 0b11010100;
	str[3] = 0b10001000;
	str[4] = 0b11100001;
	str[5] = 0b10000110;
	str[6] = 0b10001011;

	write(1, str, 7);
	return (0);
}
