/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/07/16 17:39:17 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		sconv(t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;

	sptr = sel_arglist(pfs)->str;
	if (!sptr)
	{
		s = ft_strnew(6);
		ft_strcpy(s, "(null)");
		len = 6;
	}
	else
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
	}
	pfs->converted = 1;
	if (pfs->prec && len > pfs->precvalue)
		s = precf(s, &len, pfs);
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
