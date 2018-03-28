/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_length_j.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 13:54:19 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 16:00:53 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_length_j(const char *str, fstr_t *ptrfstring)
{
	if (*str == 'j')
	{
		ptrfstring->lengthmdf[4] = 1;
		return (1);
	}
	return (0);
}
