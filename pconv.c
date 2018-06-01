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
	char	*sptr;
	int		len;
	int		plusp;

	plusp = 2;
	sptr = sel_arglist(ptrfstring)->str;
	if (ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(sptr, "0"))
	{
		//*s = '\0';
		s = ft_strnew(0);
		len = 0;
	}
	else
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
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
