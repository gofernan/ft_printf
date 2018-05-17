/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:45:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:52:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		lcconv(va_list ap, fstr_t *ptrfstring)
{
	wint_t		wc[2];
	char		*strconv;
	int			len;

	wc[0] = (wint_t)va_arg(ap, wint_t);
	wc[1] = '\0';
	if (MB_CUR_MAX == 4)
		strconv = utf8conv((unsigned int *)&wc);
	else
		strconv = onebyteconv(wc, ptrfstring);
	if (strconv)
	{
		if (!*wc)
			len = 1;
		else
			len = ft_strlen(strconv);
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			strconv = field_width(strconv, &len, ptrfstring);
		store_write(ptrfstring, strconv, &len);
	}
	else
		ptrfstring->counter = -1;
	if (ptrfstring->converted)
		ft_strdel(&strconv);
}
