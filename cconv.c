#include "includes/ft_printf.h"
void		cconv(va_list ap, fstr_t *ptrfstring)
{
	char a;
	char *s;
	int len;

	a = (char)va_arg(ap, int);
	if (!(s = ft_strnew(1)))
		exit (EXIT_FAILURE);
	ft_strncpy(s, &a, 1);
	ptrfstring->converted = 1;
	len = 1;
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width(s, &len, ptrfstring);
	ptrfstring->counter += write(1, s, len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
