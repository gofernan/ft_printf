#include "includes/ft_printf.h"

t_args		*sel_arglist(t_fstr *pfs)
{
	t_args	*tmpargsl;

	tmpargsl = pfs->ptrlargs;
	while	(tmpargsl->value != pfs->argov)
		tmpargsl = tmpargsl->next;
	return (tmpargsl);
}
