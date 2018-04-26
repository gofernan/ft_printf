#include <stdio.h>

int main()
{
  int x = 374;

  char *y = (char*)&x;
  printf("%c\n",*y+48);
}
