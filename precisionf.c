#include "includes/ft_printf.h"

char	*precisionf(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(ptrfstring->precisionvalue)))
		return (NULL);
	strncpy(newstr, str, ptrfstring->precisionvalue);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	//printf("len de str con precision: %d\n", *len);
	return (newstr);
}
