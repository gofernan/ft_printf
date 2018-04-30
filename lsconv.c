/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:01:26 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/30 16:35:52 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	wchar_t *wstr;
	unsigned char *strconv;
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
		strconv = onebyteconv(wstr);
	/*if (errno) // delete this delete this delete this
		write(1, "YES", 3);
		*/
	if (strconv)
	{
		len = ft_strlen((char *)strconv);
		ptrfstring->counter += write(1, strconv, len);
	}
	else
		ptrfstring->counter = -1;
}
