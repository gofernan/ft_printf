/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:01:26 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 21:52:40 by gofernan         ###   ########.fr       */
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

void	lsconv(va_list ap, t_fstr *pfs)
{
	char		*s;
	char		*sptr;
	int			len;
	int			validlen;

	if ((sptr = sel_arglist(pfs)->str))
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
		pfs->converted = 1;
	}
	else
		s = sptr;
	if (MB_CUR_MAX != 4)
	{
		if ((validlen = sel_arglist(pfs)->validlen))
		{
			if ((pfs->prec && pfs->precvalue >= validlen) || !pfs->prec)
			{
				if (pfs->converted)
				{
					ft_strdel(&s);
					pfs->converted = 0;
				}
			}
		}
	}
	if (s)
	{
		if (pfs->prec && len > pfs->precvalue)
		{
			if (MB_CUR_MAX == 4)
				s = precfw(s, &len, pfs);
			else
				s = precf(s, &len, pfs);
		}
		if (pfs->fwidth && len < pfs->fwidthvalue)
			s = field_width(s, &len, pfs);
		store_write(pfs, s, &len);
	}
	else
		pfs->counter = -1;
	if (pfs->converted)
		ft_strdel(&s);
}
