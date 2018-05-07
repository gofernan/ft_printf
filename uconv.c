/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:35:16 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:36:14 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		uconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	int		len;

	if (ptrfstring->convesp == 'U')
		s = ft_uimaxtoa(va_arg(ap, unsigned long));
	else if (ptrfstring->lengthmdf[0])
		s = ft_uimaxtoa((unsigned char)va_arg(ap, unsigned int));
	else if (ptrfstring->lengthmdf[1])
		s = ft_uimaxtoa((unsigned short)va_arg(ap, unsigned int));
	else if (ptrfstring->lengthmdf[2])
		s = ft_uimaxtoa(va_arg(ap, unsigned long));
	else if (ptrfstring->lengthmdf[3])
		s = ft_uimaxtoa(va_arg(ap, unsigned long long));
	else if (ptrfstring->lengthmdf[4])
		s = ft_uimaxtoa(va_arg(ap, uintmax_t));
	else if (ptrfstring->lengthmdf[5])
		s = ft_uimaxtoa(va_arg(ap, ptrdiff_t));
	else if (ptrfstring->lengthmdf[6])
		s = ft_uimaxtoa(va_arg(ap, size_t));
	else
		s = ft_uimaxtoa(va_arg(ap, unsigned int));
	ptrfstring->converted = 1;
	if (ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(s, "0"))
	{
		ft_strdel(&s);
		s = ft_strnew(0);
		ptrfstring->converted = 1;
	}
	len = ft_strlen(s);
	if (ptrfstring->precision && ptrfstring->precisionvalue > len)
		s = precisiondigits(s, &len, 0, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width_num(s, &len, ptrfstring);
	ptrfstring->counter += write(1, s, len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
