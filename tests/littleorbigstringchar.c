#include <stdio.h>
int main(void)
{
char *s= "ABCDEF";
int *p = (int *)s;
printf("%d",*(p+1)); // prints 17475 (value of DC)
return (0);
}
