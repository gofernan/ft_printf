#include "includes/ft_printf.h"

void		fconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	int		len;

	s = sel_arglist(pfs)->str;
	pfs->converted = 1;
	len = ft_strlen(s);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
