#include "includes/ft_printf.h"
void		lcconv(va_list ap, fstr_t *ptrfstring)
{
	wint_t wc[2];
	char *strconv;
	int len;

	wc[0] = (wint_t)va_arg(ap, wint_t);
	wc[1] = '\0';
	if (__mb_cur_max == 4)
		strconv = utf8conv((unsigned int *)&wc);
	else
		strconv = onebyteconv(wc, ptrfstring);
	if (strconv)
	{
		if (!*wc)
			len = 1;
		else
			len = ft_strlen(strconv);
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			strconv = field_width(strconv, &len, ptrfstring);
		ptrfstring->counter += write(1, strconv, len);
	}
	else
		ptrfstring->counter = -1;
	if (ptrfstring->converted)
		ft_strdel(&strconv);
}
