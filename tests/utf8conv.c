#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <stdint.h>
int main(int argc, char **argv)
{
	uint32_t nb = 0xff;
	uint32_t mask = 0xff;
	setlocale(LC_ALL, "es_ES.utf-8");
	int a = 8;
	wchar_t *str = L"Hoǻ€la a todo el mundo";
	int counter;

	counter = 0;
	printf("value es: %d\n", a >> 1);
	printf("str es: %ls\n", str);
	printf("mas applied: %d\n", nb & mask);
	printf("len de str: %d\n", counter);
	while (*str++)
	{
		if (*str < 0x0080)
			counter++;
		else if (*str <0x0800)
			counter += 2;
		else if (*str < 0x10000)
			counter += 3;
		else
			counter += 4;
	}
	printf("counter = %d\n", counter);
	return (0);
}
