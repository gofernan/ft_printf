/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:38:05 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
void	sconv(va_list ap, fstr_t *ptrfstring)
{
	char *s;
	int len;

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
	//if (ptrfstring->literal)
	//	ptrfstring->counter += write(1, ptrfstring->literalv, ft_strlen(ptrfstring->literalv));
	//ptrfstring->counter += write(1, s, len);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
