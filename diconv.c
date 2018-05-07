#include "includes/ft_printf.h"
void		diconv(va_list ap, fstr_t *ptrfstring)
{
	char *s;
	int len;
	int plusp;

	plusp = 0;
	if (ptrfstring->convesp == 'D')
		s = ft_ltoa(va_arg(ap, long int));
	else if (ptrfstring->lengthmdf[0])
		s = ft_itoa((signed char)va_arg(ap, int));
	else if (ptrfstring->lengthmdf[1])
		s = ft_itoa((short)va_arg(ap, int));
	else if (ptrfstring->lengthmdf[2])
		s = ft_ltoa(va_arg(ap, long));
	else if (ptrfstring->lengthmdf[3])
		s = ft_lltoa(va_arg(ap, long long));
	else if (ptrfstring->lengthmdf[4])
		s = ft_imaxtoa(va_arg(ap, size_t));
	//else if (ptrfstring->lengthmdf[5])
	//	s = diconvt(ap, ptrfstring);
	else if (ptrfstring->lengthmdf[6])
		s = ft_imaxtoa(va_arg(ap, intmax_t));
	else
		s = ft_itoa(va_arg(ap, int));
	ptrfstring->converted = 1;
	if (ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(s, "0"))
	{
		ft_strdel(&s);
		s = ft_strnew(0);
		ptrfstring->converted = 1;
	}
	len = ft_strlen(s);
	if (*s == '-')
		plusp = 1;
	if (ptrfstring->precision && ptrfstring->precisionvalue > (len - plusp))
		s = precisiondigits(s, &len, plusp, ptrfstring);
	if (ptrfstring->flags[3] && !ptrfstring->flags[4] && !plusp)
		s = flag_space(s, &len, ptrfstring);
	if (ptrfstring->flags[4] && !plusp)
		s = flag_plus(s, &len, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width_num(s, &len, ptrfstring);
	ptrfstring->counter += write(1, s, len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
