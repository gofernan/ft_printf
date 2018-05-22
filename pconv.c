/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:23:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:23:59 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	int		len;
	int		plusp;

	if (ptrfstring->precheck)
		store_arglist(ptrfstring);
	else
	{
		plusp = 2;
		//s = ft_uimaxtoa_base((va_arg(ap, uintmax_t)), 16, 0);
		s = sel_arglist(ptrfstring);
		len = ft_strlen(s);
		if (ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(s, "0"))
		{
			*s = '\0';
			len = 0;
		}
		ptrfstring->converted = 1;
		s = flag_sharp(s, &len, ptrfstring);
		if (ptrfstring->precision && ptrfstring->precisionvalue > (len - plusp))
			s = precisiondigits(s, &len, plusp, ptrfstring);
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			s = field_width_num(s, &len, ptrfstring);
		store_write(ptrfstring, s, &len);
		if (ptrfstring->converted)
			ft_strdel(&s);
	}
}
