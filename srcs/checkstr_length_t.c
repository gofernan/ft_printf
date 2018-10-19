/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_t.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:57:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 16:03:17 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			checkstr_length_t(const char *str, t_fstr *pfs)
{
	if (*str == 't')
	{
		pfs->lengthmdf[5] = 1;
		return (1);
	}
	return (0);
}
