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

char		*check_locale_lcconv(va_list ap, t_args *tmpargsl)
{
	wint_t		wc[2];
	char		*s;

	wc[0] = (wint_t)va_arg(ap, wint_t);
	wc[1] = '\0';
	if (MB_CUR_MAX == 4)
		s = utf8conv((unsigned int *)&wc);
	else
		s = onebyteconv(wc, tmpargsl);
	return (s);
}

void		lcconv(va_list ap, fstr_t *ptrfstring)
{
	int			len;
	int			validlen;
	char		*s;
	char		*sptr;

	if ((sptr = sel_arglist(ptrfstring)->str))
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
		ptrfstring->converted = 1;
	}
	else
		s = sptr;
	if (MB_CUR_MAX != 4)
	{
		if ((validlen = sel_arglist(ptrfstring)->validlen))
		{
			if ((ptrfstring->precision && ptrfstring->precisionvalue >= validlen) || !ptrfstring->precision)
			{
				if (ptrfstring->converted)
				{
					ft_strdel(&s);
					ptrfstring->converted = 0;
				}
			}
		}
	}
	if (s)
	{
		//if (!*wc)
		if (!*s) // not clear
			len = 1;
		//else
		//	len = ft_strlen(s);
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			s = field_width(s, &len, ptrfstring);
		store_write(ptrfstring, s, &len);
	}
	else
		ptrfstring->counter = -1;
	if (ptrfstring->converted)
		ft_strdel(&s);
}
