#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	//char *str = "hello how are y     ";
	char *str2 = "";
	printf("return es %d", write(1, str2, 0));
	return (0);
}
