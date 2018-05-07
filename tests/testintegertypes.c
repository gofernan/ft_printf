#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
int multiplication(int nb)
{
	return (nb * nb);
}

int main (void)
{
	char nb = 250;
	printf("multiplication %d", multiplication(nb));
	return (0);
}
