#include "includes/ft_printf.h"

void		fill_defaultv(t_args *tmpargsl, int *i)
{
	tmpargsl->value = *i;
	tmpargsl->conv = 's';
	tmpargsl->mdf = -1;
	tmpargsl->str = NULL;
	tmpargsl->next = NULL;
}

void		retr_arglist(va_list ap, t_fstr *pfs)
{
	va_list ap2;
	t_args	*tmpargsl;
	int		maxorder;
	int		i;
	char	*s;

	maxorder = 1;
	i = 1;
	tmpargsl = pfs->ptrlargs;
	s = NULL;
	while (tmpargsl)
	{
		if (tmpargsl->value > maxorder)
			maxorder = tmpargsl->value;
		tmpargsl = tmpargsl->next;
	}
	tmpargsl = pfs->ptrlargs;
	while (i <= maxorder)
	{
		while (tmpargsl)
		{
			if (tmpargsl->value != i)
				tmpargsl = tmpargsl->next;
			else
				break ;
		}
		if (!tmpargsl)
		{
			tmpargsl = pfs->ptrlargs;
			while (tmpargsl)
			{
				if (!tmpargsl->next)
				{
					if (!(tmpargsl->next = (t_args *)malloc(sizeof(t_args))))
						exit(EXIT_FAILURE);
					fill_defaultv(tmpargsl->next, &i);
					tmpargsl = tmpargsl->next;
				}
				tmpargsl = tmpargsl->next;
			}
		}
		tmpargsl = pfs->ptrlargs;
		i++;
	}
	va_copy(ap2, ap);
	i = 1;
	while (i <= maxorder)
	{
		while (tmpargsl->value != i)
		{
			if (!(tmpargsl = tmpargsl->next))
				break ;
		}
	if (tmpargsl->conv == 's' && tmpargsl->mdf != 2)
		tmpargsl->str = va_arg(ap2, char *);
	else if (tmpargsl->conv == 'S' || tmpargsl->conv == 's')
		tmpargsl->str = check_locale_lsconv(ap2, tmpargsl);
	else if (tmpargsl->conv == 'd' || tmpargsl->conv == 'i' ||
			tmpargsl->conv == 'D')
		tmpargsl->str = dimdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'u' || tmpargsl->conv == 'U')
		tmpargsl->str = umdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'o' || tmpargsl->conv == 'O')
		tmpargsl->str = omdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'X' || tmpargsl->conv == 'x')
		tmpargsl->str = xmdfs(ap2, tmpargsl);
	else if (tmpargsl->conv == 'c' && tmpargsl->mdf != 2)
		tmpargsl->str = cconva(ap2, pfs);
	else if (tmpargsl->conv == 'C' || tmpargsl->conv == 'c')
		tmpargsl->str = check_locale_lcconv(ap2, tmpargsl);
	else if (tmpargsl->conv == 'p')
		tmpargsl->str = ft_uimaxtoa_base((va_arg(ap2, uintmax_t)), 16, 0);
	else if (tmpargsl->conv == 'f' || tmpargsl->conv == 'F')
		tmpargsl->str = ft_ftoa(ap2);
	else if (tmpargsl->conv == 'b')
		tmpargsl->str = ft_binary((va_arg(ap2, intmax_t)));
	tmpargsl = pfs->ptrlargs;
	i++;
	}
	va_end(ap2);
}
