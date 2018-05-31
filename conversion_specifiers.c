/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_specifiers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:41:53 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:16:49 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			conversion_specifiers(const char *str, fstr_t *ptrfstring)
{
	int		i;
	char	conversors[CONV_N + 1];

	//ft_strcpy(conversors, "sSpdDioOuUxXcCfF");
	ft_strcpy(conversors, CONVERSORS);
	conversors[CONV_N] = '\0';
	i = 0;
	while (i < CONV_N)
	{
		if (*str == conversors[i])
		{
			ptrfstring->convesp = conversors[i];
			return (1);
		}
		i++;
	}
	return (0);
}
