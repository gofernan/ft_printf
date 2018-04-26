#include <stdio.h>
#include <wchar.h>
#include <unistd.h>
#include <locale.h>

int main(int argc, char **argv)
{
	//setlocale(LC_ALL, "en_US.utf8");

	//wchar_t *strl = L"hola como estas";
	//unsigned char testc[4];
	wchar_t testc;
	long number;

	//testc[0] = 0b11000111; UTF8 first byte
	//testc[1] = 0b10111011; UTF8 second byte
	testc = 0b00000000000000000000000111111011; //UTF32BE doesnt work
	number = 507;
	//testc[0] = 0b00000000; UTF32BE doesnt work
	//testc[1] = 0b00000000; UTF32BE
	//testc[2] = 0b00000001; UTF32BE
	//testc[3] = 0b11111011; UTF32BE
	//printf("%ls", strl);
	//write(1, &testc, 4);
	printf("testc value: %d\n", testc);
	if (testc == number)
		write(1, "y", 1);
	printf("sizeof long %d\n", sizeof(long));
	//write(1, "\n", 1);
	//write(1, strl+1, 2);
	//write(1, L"hola como estas", 1);
	return (0);
}
