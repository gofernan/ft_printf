#include "includes/ft_printf.h"
static char		*pluspr(char *str, int *len, int plusp, fstr_t *ptrfstring)
{
	char *newstr;

	newstr = NULL;
	if (!(newstr = ft_strnew(ptrfstring->precisionvalue + plusp)))
		exit (EXIT_FAILURE);
	if (plusp == 1)
		ft_memset(newstr, '-', 1);
	else if (plusp == 2)
	{
		if (ptrfstring->convesp == 'x')
			ft_strcpy(newstr, "0x");
		else
			ft_strcpy(newstr, "0X");
	}
		ft_memset(newstr + plusp, '0', ptrfstring->precisionvalue + plusp - *len);
		ft_strcat(newstr, str + plusp);
	return (newstr);
}

char		*precisiondigits(char *str, int *len, int plusp, fstr_t *ptrfstring)
{
	char *newstr;

	if (plusp)
		newstr = pluspr(str, len, plusp, ptrfstring);
	else
	{
		if (!(newstr = ft_strnew(ptrfstring->precisionvalue)))
			exit (EXIT_FAILURE);
		ft_memset(newstr, '0', ptrfstring->precisionvalue - *len);
		ft_strcat(newstr, str);
	}
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}	
