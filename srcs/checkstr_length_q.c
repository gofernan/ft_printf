/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_q.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:16:02 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:16:16 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			checkstr_length_q(const char *str, t_fstr *pfs)
{
	if (*str == 'q')
	{
		pfs->lengthmdf[7] = 1;
		return (1);
	}
	return (0);
}
