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

void		lcconv(va_list ap, t_fstr *pfs)
{
	int			len;
	int			validlen;
	char		*s;
	char		*sptr;

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
		//if (!*wc)
		if (!*s) // not clear
			len = 1;
		//else
		//	len = ft_strlen(s);
		if (pfs->fwidth && len < pfs->fwidthvalue)
			s = field_width(s, &len, pfs);
		store_write(pfs, s, &len);
	}
	else
		pfs->counter = -1;
	if (pfs->converted)
		ft_strdel(&s);
}
