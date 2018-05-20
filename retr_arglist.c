#include "includes/ft_printf.h"

void		retr_arglist(va_list ap, ptrfstring)
{
	va_list ap2;

	va_copy(ap2, ap);
	while (ptrfstring->ptrlargs)
	{
	if (ptrfstring->convesp == 's' && !(ptrfstring->lengthmdf[2]))
		sconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'S' || ptrfstring->convesp == 's')
		lsconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'd' || ptrfstring->convesp == 'i' ||
			ptrfstring->convesp == 'D')
		diconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'u' || ptrfstring->convesp == 'U')
		uconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'o' || ptrfstring->convesp == 'O')
		oconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'X' || ptrfstring->convesp == 'x')
		xconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'c' && !ptrfstring->lengthmdf[2])
		cconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'C' || ptrfstring->convesp == 'c')
		lcconv(ap, ptrfstring);
	else if (ptrfstring->convesp == 'p')
		pconv(ap, ptrfstring);
	else
		percent(str[*i], ptrfstring);
	return (0);

