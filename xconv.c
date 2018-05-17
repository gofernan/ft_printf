/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:33:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:26:36 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*xmdfs(va_list ap, fstr_t *ptrfstring, char *s)
{
	int		altform;

	altform = (ptrfstring->convesp == 'X') ? 1 : 0;
	if (ptrfstring->lengthmdf[7])
		s = ft_uimaxtoa_base(va_arg(ap, u_quad_t), 16, altform);
	else if (ptrfstring->lengthmdf[6])
		s = ft_uimaxtoa_base(va_arg(ap, size_t), 16, altform);
	else if (ptrfstring->lengthmdf[5])
		s = ft_uimaxtoa_base(va_arg(ap, ptrdiff_t), 16, altform);
	else if (ptrfstring->lengthmdf[4])
		s = ft_uimaxtoa_base(va_arg(ap, uintmax_t), 16, altform);
	else if (ptrfstring->lengthmdf[3])
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long long), 16, altform);
	else if (ptrfstring->lengthmdf[2])
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long), 16, altform);
	else if (ptrfstring->lengthmdf[1])
		s = ft_uimaxtoa_base((unsigned short)va_arg(ap, unsigned int), 16, altform);
	else if (ptrfstring->lengthmdf[0])
		s = ft_uimaxtoa_base((unsigned char)va_arg(ap, unsigned int), 16, altform);
	else
		s = ft_uimaxtoa_base(va_arg(ap, unsigned int), 16, altform);
	if (!s)
		exit(EXIT_FAILURE);
	ptrfstring->converted = 1;
	return (s);
}

void			xconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	int		len;
	int		plusp;

	plusp = 0;
	s = NULL;
	s = xmdfs(ap, ptrfstring, s);
	len = ft_strlen(s);
	if (ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(s, "0"))
	{
		*s = '\0';
		len = 0;
	}
	if (ptrfstring->flags[0] && ft_strcmp(s, "0") && len > 0)
	{
		s = flag_sharp(s, &len, ptrfstring);
		plusp = 2;
	}
	if (ptrfstring->precision && ptrfstring->precisionvalue > (len - plusp))
		s = precisiondigits(s, &len, plusp, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width_num(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
