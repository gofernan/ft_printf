/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_fwidth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:39:27 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/20 20:29:18 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int checkstr_fwidth(const char *str, fstr_t *ptrfstring)
{
	int i;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] != '$' && i > 0)
	{
		ptrfstring->fwidthvalue = ft_memalloc(i + 1);
		ft_strncpy(ptrfstring->fwidthvalue, str, i);
		ptrfstring->fwidth = 1;
		return (1);
	}
	return (0);
}
