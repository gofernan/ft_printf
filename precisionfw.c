#include "includes/ft_printf.h"

char	*precisionfw(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	while ((((unsigned char)str[ptrfstring->precisionvalue]) >> 6) == 0x02)
		ptrfstring->precisionvalue--;
	if (!(newstr = ft_strnew(ptrfstring->precisionvalue)))
		return (NULL);
	strncpy(newstr, str, ptrfstring->precisionvalue);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
