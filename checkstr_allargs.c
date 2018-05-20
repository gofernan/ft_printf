#include "includes/ft_printf.h"

void		checkstr_allargs(const char *str, fstr_t *ptrfstring, va_list ap)
{
	int i;
	int go;
	va_list ap2;

	i = 0;
	go = 0;
	ptrfstring->precheck = 1;
	va_copy(ap2, ap);
	while (str[i] != '\0')
	{
		if (go == 0)
		{
			if (str[i] == '%')
				go = 1;
		}
		else
		{
			go = checkstr_inside(str, ptrfstring, ap2, &i);
		}
		i++;
	}
	va_end(ap2);
}
