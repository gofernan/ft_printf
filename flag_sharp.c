#include "includes/ft_printf.h"
static char		*flag_sharp_o(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(*len + 1)))
		exit (EXIT_FAILURE);
	*newstr = '0';
	ft_strcpy(newstr + 1, str);
	*len += 1;
	return (newstr);
}
static char		*flag_sharp_x(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(*len + 2)))
		exit (EXIT_FAILURE);
	if (ptrfstring->convesp == 'x')
		ft_strcpy(newstr, "0x");
	else
		ft_strcpy(newstr, "0X");
	ft_strcpy(newstr + 2, str);
	*len += 2;
	return (newstr);
}

char		*flag_sharp(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;
	int lenalt;

	if (ptrfstring->convesp == 'x' || ptrfstring->convesp == 'X')
		newstr = flag_sharp_x(str, len, ptrfstring);
	else if (ptrfstring->convesp == 'o' || ptrfstring->convesp == 'O')
		newstr = flag_sharp_o(str, len, ptrfstring);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	return (newstr);
}
