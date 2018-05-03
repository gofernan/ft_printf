#include "includes/ft_printf.h"
char		*diconvll(va_list ap, fstr_t *ptrfstring)
{
	long long longlongll;

	longlongll = va_arg(ap, long long);
	return (ft_lltoa(longlongll));
}

char		*diconvl(va_list ap, fstr_t *ptrfstring)
{
	long longl;

	longl = va_arg(ap, long);
	return(ft_ltoa(longl));
}

char		*diconvh(va_list ap, fstr_t *ptrfstring)
{
	int shorth;

	shorth = (short)va_arg(ap, int);
	return(ft_itoa(shorth));
}
char		*diconvhh(va_list ap, fstr_t *ptrfstring)
{
	int charhh;

	charhh = (signed char)va_arg(ap, int);
	return(ft_itoa(charhh));
}
void		diconv(va_list ap, fstr_t *ptrfstring)
{
	char *s;
	int len;
	int negnumber;

	negnumber = 0;
	if (ptrfstring->lengthmdf[0])
		s = diconvhh(ap, ptrfstring);
	else if (ptrfstring->lengthmdf[1])
		s = diconvh(ap, ptrfstring);
	else if (ptrfstring->lengthmdf[2] || ptrfstring->convesp == 'D')
		s = diconvl(ap, ptrfstring);
	else if (ptrfstring->lengthmdf[3])
		s = diconvll(ap,ptrfstring);
	/*else if (ptrfstring->lengthmdf[4])
		diconvj(ap,ptrfstring);
	else if (ptrfstring->lengthmdf[5])
		diconvt(ap, ptrfstring);
	if (ptrfstring->lengthmdf[6])
		diconvz(ap, ptrfstring);
		*/
	else
		s = ft_itoa(va_arg(ap, int));
	len = ft_strlen(s);
	if (*s == '-')
		negnumber = 1;
	if (ptrfstring->precision && ptrfstring->precisionvalue > (len - negnumber))
		s = precisiondigits(s, &len, negnumber, ptrfstring);
	if (ptrfstring->flags[3] && !ptrfstring->flags[4] && !negnumber)
		s = flag_space(s, &len, ptrfstring);
	if (ptrfstring->flags[4] && !negnumber)
		s = flag_plus(s, &len, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width_num(s, &len, ptrfstring);
	ptrfstring->counter = write(1, s, len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
