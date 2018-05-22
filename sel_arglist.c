#include "includes/ft_printf.h"

char		*sel_arglist(fstr_t *ptrfstring)
{
	t_args	*tmpargsl;

	tmpargsl = ptrfstring->ptrlargs;
	while	(tmpargsl->value != ptrfstring->argordervalue)
		tmpargsl = tmpargsl->next;
	return (tmpargsl->str);
}
