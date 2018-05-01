#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(void)
{
	char *str1 = NULL;
	char *str2 = "\0";
	char char2 = '\0';

	if (str2)
		printf("Dentro de string 0");
	if (str1)
		printf("Dentro de string null");
	if (char2)
		printf("Dentro de char");
	printf("value %d", write(1, "\0\0", 0));
	printf("value %d", write(1, NULL, 1));
	return (0);
}
