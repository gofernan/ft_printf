#include "includes/ft_printf.h"

static void fwaux(char *str, char *newstr, int *len, fstr_t *ptrfstring)
{
		if (ptrfstring->flags[1] && !ptrfstring->precision)
		{
			if (*str == '-' || *str == ' ' || *str == '+')
			{
				*newstr = *str;
				ft_memset(newstr + 1, '0', ptrfstring->fwidthvalue - *len);
				ft_strcat(newstr, str + 1);
			}
			else if (*(str + 1) == 'X' || *(str + 1) == 'x')
			{
				ft_strncpy(newstr, str, 2);
				ft_memset(newstr + 2, '0', ptrfstring->fwidthvalue - *len);
				ft_strcat(newstr, str + 2);
			}
			else
			{
				ft_memset(newstr, '0', ptrfstring->fwidthvalue - *len);
				ft_strcat(newstr, str);
			}
		}
		else
		{
			ft_memset(newstr, ' ', ptrfstring->fwidthvalue - *len);
			ft_strcat(newstr, str);
		}
}

char		*field_width_num(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(ptrfstring->fwidthvalue)))
		exit (EXIT_FAILURE);
	if (ptrfstring->flags[2])
	{
		ft_strcpy(newstr, str);
		ft_memset(ft_strchr(newstr, '\0'), ' ', ptrfstring->fwidthvalue - *len);
	}
	else
		fwaux(str, newstr, len, ptrfstring);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
