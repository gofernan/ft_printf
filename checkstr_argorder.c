/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_argorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:10:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 18:55:15 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_argorder(const char *str, fstr_t *ptrfstring)
{
	int i;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] == '$' && i > 0)
	{
		ptrfstring->argordervalue = ft_memalloc(i + 1);
		ft_strncpy(ptrfstring->argordervalue, str, i);
		ptrfstring->argorder = 1;
		return (1);
	}
	return (0);
}
