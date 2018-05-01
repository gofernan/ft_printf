/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:01:26 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/30 19:20:12 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	wchar_t *wstr;
	char *strconv;
	char *strnull;
	int len;

	if (!(wstr = va_arg(ap, wchar_t *)))
	{
		strnull = ft_strnew(7);
		ft_strcpy(strnull, "(null)");
		ptrfstring->converted = 1;
	}
	if (__mb_cur_max == 4)
		strconv = utf8conv((unsigned int *)wstr);
	else
		strconv = onebyteconv(wstr, ptrfstring);
	/*if (errno) // delete this delete this delete this
		write(1, "YES", 3);
		*/
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
	if (strconv)
		ptrfstring->counter += write(1, strconv, len);
	else
		ptrfstring->counter = -1;
		//ptrfstring->counter = write(1, strconv, len); 
}
