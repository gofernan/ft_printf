/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_z.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:01:17 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 16:03:40 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			checkstr_length_z(const char *str, t_fstr *pfs)
{
	if (*str == 'z')
	{
		pfs->lengthmdf[6] = 1;
		return (1);
	}
	return (0);
}
