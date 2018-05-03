#include "includes/ft_printf.h"

char		*field_width_num(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(ptrfstring->fwidthvalue)))
		return (NULL);
	if (ptrfstring->flags[2])
	{
		ft_strcpy(newstr, str);
		ft_memset(ft_strchr(newstr, '\0'), '0', ptrfstring->fwidthvalue - *len);
	}
	else
	{
		ft_memset(newstr, ' ', ptrfstring->fwidthvalue - *len);
		ft_strcat(newstr, str);
	}
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
