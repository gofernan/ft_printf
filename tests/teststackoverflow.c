#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
	setlocale(LC_ALL, "");
	wchar_t wc = L'\x3b1';	
	  //setlocale(LC_ALL, "en_US.UTF-8");

	    wchar_t *s;
	    s = (wchar_t *) malloc(sizeof(wchar_t) * 2);
	    s[0] = 0xC3;
	    s[1] = 0xA4;
		if (printf("%ls\n", s) < 0)
		{
			perror("printf");
		}
		if (printf("%lc\n", wc) < 0)
		{
			perror("printf");
		}
		 free(s);
  		return (0);
}
