/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:45:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:29:36 by gofernan         ###   ########.fr       */
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

static char		*check_utf8all(t_fstr *pfs, char *s, int *len)
{
	int valid;
	if (MB_CUR_MAX != 4)
	{
		if ((valid = sel_arglist(pfs)->validlen))
		{
			if ((pfs->prec && pfs->precvalue >= valid) || !pfs->prec)
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
		if (!*s)
			*len = 1;
		if (pfs->fwidth && *len < pfs->fwidthvalue)
			s = field_width(s, len, pfs);
		store_write(pfs, s, len);
	}
	else
		pfs->counter = -1;
	return (s);
}

void		lcconv(t_fstr *pfs)
{
	int			len;
	char		*s;
	char		*sptr;

	len = 0;
	if ((sptr = sel_arglist(pfs)->str))
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
		pfs->converted = 1;
	}
	else
		s = sptr;
	s = check_utf8all(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
