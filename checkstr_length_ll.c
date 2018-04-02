/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_ll.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:25:41 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/02 19:24:21 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_length_ll(const char *str, fstr_t *ptrfstring)
{
	if (*str == 'l' && *(str + 1) == 'l')
	{
		ptrfstring->lengthmdf[3] = 1;
		return (1);
	}
	return (0);
}
