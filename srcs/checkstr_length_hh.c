/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_hh.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:52:39 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 15:59:49 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			checkstr_length_hh(const char *str, t_fstr *pfs)
{
	if (*str == 'h' && *(str + 1) == 'h')
	{
		pfs->lengthmdf[0] = 1;
		return (1);
	}
	return (0);
}
