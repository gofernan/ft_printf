#include "includes/ft_printf.h"

int			checkstr_length_q(const char *str, fstr_t *ptrfstring)
{
	if (*str == 'q')
	{
		ptrfstring->lengthmdf[7] = 1;
		return (1);
	}
	return (0);
}
