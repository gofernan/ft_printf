#include "includes/ft_printf.h"

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	va_arg(ap, wchar_t *);

