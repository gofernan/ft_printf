/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convsp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:41:53 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:18:32 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			convsp(const char *str, t_fstr *pfs)
{
	int		i;
	char	conversors[CONV_N + 1];

	ft_strcpy(conversors, CONVERSORS);
	conversors[CONV_N] = '\0';
	i = 0;
	while (i < CONV_N)
	{
		if (*str == conversors[i])
		{
			pfs->conv = conversors[i];
			return (1);
		}
		i++;
	}
	return (0);
}
