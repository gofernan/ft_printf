/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 11:34:07 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:14:40 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_flags(const char *str, fstr_t *ptrfstring)
{
	int		i;
	char	flags[7];

	strcpy(flags, "#0- +'");
	i = 0;
	while (i < 7)
	{
		if	(*str == flags[i])
		{
			ptrfstring->flags[i] = 1;
			return (1);
		}
		i++;
	}
	return 0;
}
