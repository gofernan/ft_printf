/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:36:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/02 19:24:39 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_length_l(const char *str, t_fstr *pfs)
{
	if (*str == 'l' && *(str + 1) != 'l')
	{
		pfs->lengthmdf[2] = 1;
		return (1);
	}
	return (0);
}
