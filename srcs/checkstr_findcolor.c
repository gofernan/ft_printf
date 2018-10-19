/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_findcolor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:38:11 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/04 10:38:15 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			checkstr_findcolor(const char *str, t_fstr *pfs, int *i)
{
	int poscolor;
	int aux;

	aux = 1;
	if ((poscolor = checkstr_colors(str, pfs, i)))
	{
		pfs->lnchars += 5;
		*i += poscolor - 1;
	}
	else
	{
		store_write(pfs, &str[*i - 1], &aux);
		pfs->lnchars += 1;
		*i = *i - 1;
	}
	return (0);
}
