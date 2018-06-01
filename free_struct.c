#include "includes/ft_printf.h"

void	free_struct(fstr_t *ptrfstring)
{
	t_args *tmpstru;
	t_args *next;

	tmpstru = ptrfstring->ptrlargs;
	next = ptrfstring->ptrlargs;
	if (tmpstru)
	{
		while (next)
		{
			tmpstru = next;
			next = tmpstru->next;
			if (tmpstru->str && !(tmpstru->convesp == 's' && tmpstru->mdf != 2))
				ft_strdel(&tmpstru->str);
			free(tmpstru);
		}
	}
}
