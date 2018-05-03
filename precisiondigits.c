#include "includes/ft_printf.h"

char		*precisiondigits(char *str, int *len, int negnumber, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(ptrfstring->precisionvalue + negnumber)))
		return (NULL);
	if (negnumber)
	{
		ft_memset(newstr, '-', 1);
		ft_memset(newstr + 1, '0', ptrfstring->precisionvalue + 1 - *len);
		ft_strcat(newstr, str + 1);
	}
	else
	{
		ft_memset(newstr, '0', ptrfstring->precisionvalue - *len);
		ft_strcat(newstr, str);
	}
	/* if converted previously (rare)
	 * ft_strdel(&str)
	 */
	ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}	
