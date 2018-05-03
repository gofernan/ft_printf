#include "includes/ft_printf.h"

char *flag_plus(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(*len + 1)))
		return (NULL);
	*newstr = '+';
	ft_strcpy(newstr + 1, str);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len += 1;
	return (newstr);
}
