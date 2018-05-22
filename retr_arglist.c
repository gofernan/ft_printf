#include "includes/ft_printf.h"

void		fill_defaultv(t_args *tmpargsl, int *i)
{
	tmpargsl->value = *i;
	tmpargsl->convesp = 's';
	tmpargsl->mdf = -1;
	tmpargsl->str = NULL;
	tmpargsl->next = NULL;
}

void		retr_arglist(va_list ap, fstr_t *ptrfstring)
{
	va_list ap2;
	t_args	*tmpargsl;
	int		maxorder;
	int		i;
	char	*s;

	maxorder = 1;
	i = 1;
	tmpargsl = ptrfstring->ptrlargs;
	s = NULL;
	while (tmpargsl)
	{
		if (tmpargsl->value > maxorder)
			maxorder = tmpargsl->value;
		tmpargsl = tmpargsl->next;
	}
	tmpargsl = ptrfstring->ptrlargs;
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
			tmpargsl = ptrfstring->ptrlargs;
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
		tmpargsl = ptrfstring->ptrlargs;
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
	if (tmpargsl->convesp == 's' && tmpargsl->mdf != 2)
		tmpargsl->str = va_arg(ap2, char *);
	else if (tmpargsl->convesp == 'S' || tmpargsl->convesp == 's')
		tmpargsl->str = check_locale_lsconv(ap2, tmpargsl);
	else if (tmpargsl->convesp == 'd' || tmpargsl->convesp == 'i' ||
			tmpargsl->convesp == 'D')
		tmpargsl->str = dimdfs(ap2, tmpargsl);
	else if (tmpargsl->convesp == 'u' || tmpargsl->convesp == 'U')
		tmpargsl->str = umdfs(ap2, tmpargsl);
	else if (tmpargsl->convesp == 'o' || tmpargsl->convesp == 'O')
		tmpargsl->str = omdfs(ap2, tmpargsl);
	else if (tmpargsl->convesp == 'X' || tmpargsl->convesp == 'x')
		tmpargsl->str = xmdfs(ap2, tmpargsl);
	else if (tmpargsl->convesp == 'c' && tmpargsl->mdf != 2)
		tmpargsl->str = cconva(ap2, ptrfstring);
	else if (tmpargsl->convesp == 'C' || tmpargsl->convesp == 'c')
		tmpargsl->str = check_locale_lcconv(ap2, tmpargsl);
	else if (tmpargsl->convesp == 'p')
		tmpargsl->str = ft_uimaxtoa_base((va_arg(ap, uintmax_t)), 16, 0);
	//else
	//	percent(str[*i], ptrfstring);
	tmpargsl = ptrfstring->ptrlargs;
	i++;
	}
	va_end(ap2);
}
