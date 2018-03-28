/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_l.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:36:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 17:21:16 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_length_l(const char *str, fstr_t *ptrfstring)
{
	if (*str == 'l' && *(str + 1) != 'l')
	{
		ptrfstring->lengthmdf[3] = 1;
		return (1);
	}
	return (0);
}
