/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_h.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 15:54:29 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 15:59:33 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_length_h(const char *str, fstr_t *ptrfstring)
{
	if (*str == 'h' && *(str + 1) != 'h')
	{
		ptrfstring->lengthmdf[1] = 1;
		return (1);
	}
	return (0);
}
