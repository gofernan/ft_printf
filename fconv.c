#include "includes/ft_printf.h"

void		fconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	int		len;

	s = sel_arglist(ptrfstring)->str;
	ptrfstring->converted = 1;
	len = ft_strlen(s);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}