#include "includes/ft_printf.h"

int			checkstr_colors(const char *str, t_fstr *pfs, int *i)
{
	char	*colorchar;
	int		colsqlen;

	colsqlen = 5;
	if (!ft_strncmp(str[*i], "{red}", 5))
	{
		store_write(pfs, "\x1b[31m", &colsqlen);
		return (5);
	}
	return (0);
}
