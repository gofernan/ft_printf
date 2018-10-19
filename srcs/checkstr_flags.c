/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:34:07 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:20:43 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			checkstr_flags_pc(const char *str)
{
	int i;

	i = 0;
	while (i < FLAGS_N)
	{
		if (*str == FLAGS[i])
			return (1);
		i++;
	}
	return (0);
}

int			checkstr_flags(const char *str, t_fstr *pfs)
{
	if (pfs->precheck)
		return (checkstr_flags_pc(str));
	if (*str == '#')
		pfs->flags[0] = 1;
	else if (*str == '0')
		pfs->flags[1] = 1;
	else if (*str == '-')
		pfs->flags[2] = 1;
	else if (*str == ' ')
		pfs->flags[3] = 1;
	else if (*str == '+')
		pfs->flags[4] = 1;
	else
		return (0);
	return (1);
}
