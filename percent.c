/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:21:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:22:22 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		percent(char a, t_fstr *pfs)
{
	char	*s;
	int		len;

	len = 1;
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		exit(EXIT_FAILURE);
	ft_strncpy(s, &a, 1);
	*(s + 1) = '\0';
	pfs->converted = 1;
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
