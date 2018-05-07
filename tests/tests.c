#include <stdio.h>
int main(void)
{
	void *test;
	char a = 'a';

	test = &a;
	printf("%lu", sizeof(void *));
	printf("%p", test);
	return (0);
}
