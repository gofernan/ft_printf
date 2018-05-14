/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:01:26 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:18:03 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	wchar_t		*wstr;
	char		*strconv;
	char		*strnull;
	int			len;

	if (!(wstr = va_arg(ap, wchar_t *)))
	{
		if (!(strconv = ft_strnew(7)))
			exit(EXIT_FAILURE);
		ft_strcpy(strconv, "(null)");
		ptrfstring->converted = 1;
	}
	else
	{
		if (__mb_cur_max == 4)
			strconv = utf8conv((unsigned int *)wstr);
		else
			strconv = onebyteconv(wstr, ptrfstring);
	}
	if (strconv)
	{
		len = ft_strlen(strconv);
		if (ptrfstring->precision && len > ptrfstring->precisionvalue)
		{
			if (__mb_cur_max == 4)
				strconv = precisionfw(strconv, &len, ptrfstring);
			else
				strconv = precisionf(strconv, &len, ptrfstring);
		}
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			strconv = field_width(strconv, &len, ptrfstring);
		store_write(ptrfstring, strconv, &len);
	}
	else
		ptrfstring->counter = -1;
	if (ptrfstring->converted)
		ft_strdel(&strconv);
}
