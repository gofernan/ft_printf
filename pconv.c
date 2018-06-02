/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:23:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 21:47:53 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		pconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;
	int		plusp;

	plusp = 2;
	sptr = sel_arglist(pfs)->str;
	if (pfs->prec && pfs->precvalue == 0 && !ft_strcmp(sptr, "0"))
	{
		s = ft_strnew(0);
		len = 0;
	}
	else
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
	}
	pfs->converted = 1;
	s = flag_sharp(s, &len, pfs);
	if (pfs->prec && pfs->precvalue > (len - plusp))
		s = precdigits(s, &len, plusp, pfs);
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width_num(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
