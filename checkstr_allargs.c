#include "includes/ft_printf.h"

void		checkstr_allargs(const char *str, t_args *ptrlargs)
{
	int i;
	int go;
	int pos;

	i = 0;
	go = 0;
	pos = 0;
	while (str[i] != '\0')
	{
		if (go == 0)
		{
			if (pos = ft_strchr(&str[i], '%') - str)
			{
				i += pos - 1;
				go = 1;
			}
			else
				break ;
		}
		else
			if (checkstr_argorder(&str[i], ptrfstring, &auxshift))
				i += auxshift - 1;
