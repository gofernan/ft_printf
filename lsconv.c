#include "includes/ft_printf.h"

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	wchar_t *wstr;
	unsigned char *strconv;
	char *strnull;
	int len;

	if (!(wstr = va_arg(ap, wchar_t *)))
	{
		strnull = ft_strnew(7);
		ft_strcpy(strnull, "(null)");
		ptrfstring->converted = 1;
	}
	strconv = utf8conv((unsigned int *)wstr);
	if (errno) // delete this delete this delete this
		write(1, "YES", 3);
	if (strconv)
	{
		len = ft_strlen((char *)strconv);
		ptrfstring->counter += write(1, strconv, len);
	}
	else
		ptrfstring->counter = -1;
}
