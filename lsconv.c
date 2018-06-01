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

char	*check_locale_lsconv(va_list ap, t_args *tmpargsl)
{
	wchar_t		*wstr;
	char		*s;

	if (!(wstr = va_arg(ap, wchar_t *)))
	{
		if (!(s = (char *)malloc(sizeof(char) * 8)))
			exit(EXIT_FAILURE);
		ft_strcpy(s, "(null)");
		//ptrfstring->converted = 1;
	}
	else
	{
		if (MB_CUR_MAX == 4)
			s = utf8conv((unsigned int *)wstr);
		else
			s = onebyteconv(wstr, tmpargsl);
	}
	return (s);
}

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	char		*s;
	char		*sptr;
	int			len;
	int			validlen;

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
		if (ptrfstring->precision && len > ptrfstring->precisionvalue)
		{
			if (MB_CUR_MAX == 4)
				s = precisionfw(s, &len, ptrfstring);
			else
				s = precisionf(s, &len, ptrfstring);
		}
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			s = field_width(s, &len, ptrfstring);
		store_write(ptrfstring, s, &len);
	}
	else
		ptrfstring->counter = -1;
	if (ptrfstring->converted)
		ft_strdel(&s);
}
