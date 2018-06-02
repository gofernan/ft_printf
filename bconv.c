/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 22:02:42 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:02:51 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		bconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	int		len;

	s = sel_arglist(pfs)->str;
	len = ft_strlen(s);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
