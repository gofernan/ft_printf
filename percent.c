#include "includes/ft_printf.h"
void		percent(char a, fstr_t *ptrfstring)
{
	char	*s;
	int		len;

	len = 1;
	if (!(s = ft_strnew(1)))
		exit(EXIT_FAILURE);
	ft_strncpy(s, &a, 1);
	ptrfstring->converted = 1;
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
