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
	char	*sptr;
	int		len;

	sptr = sel_arglist(ptrfstring)->str;
	if (!sptr)
	{
		s = ft_strnew(6);
		ft_strcpy(s, "(null)");
		len = 6;
	}
	else
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
	}
	ptrfstring->converted = 1;
	if (ptrfstring->precision && len > ptrfstring->precisionvalue)
		s = precisionf(s, &len, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
