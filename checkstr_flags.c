/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:34:07 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:09:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_flags(const char *str, fstr_t *ptrfstring)
{
	if (*str == '#')
		ptrfstring->flags[0] = 1;
	else if (*str == '0')
		ptrfstring->flags[1] = 1;
	else if (*str == '-')
		ptrfstring->flags[2] = 1;
	else if (*str == ' ')
		ptrfstring->flags[3] = 1;
	else if (*str == '+')
		ptrfstring->flags[4] = 1;
	else if (*str == '\'')
		ptrfstring->flags[5] = 1;
	else
		return (0);
	return (1);
}
