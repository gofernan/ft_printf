#include "includes/ft_printf.h"

void	free_struct(t_fstr *pfs)
{
	t_args *tmpstru;
	t_args *next;

	tmpstru = pfs->ptrlargs;
	next = pfs->ptrlargs;
	if (tmpstru)
	{
		while (next)
		{
			tmpstru = next;
			next = tmpstru->next;
			if (tmpstru->str && !(tmpstru->conv == 's' && tmpstru->mdf != 2))
				ft_strdel(&tmpstru->str);
			free(tmpstru);
		}
	}
}
