
#include "includes/ft_printf.h"

void		bconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	int		len;

	s = sel_arglist(pfs)->str;
	len = ft_strlen(s);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
