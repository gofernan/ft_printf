/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:23:30 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		sconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	int		len;

	//if (ptrfstring->argorder)
	//	s = argorder(ap, ptrfstring);
	//	else if ...
	if (!(s = va_arg(ap, char *)))
	{
		s = ft_strnew(6);
		ft_strcpy(s, "(null)");
		ptrfstring->converted = 1;
	}
	len = ft_strlen(s);
	if (ptrfstring->precision && len > ptrfstring->precisionvalue)
		s = precisionf(s, &len, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
