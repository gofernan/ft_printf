/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 22:01:03 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:01:05 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_colors(const char *str, t_fstr *pfs, int *i)
{
	char	*colorchar;
	int		colsqlen;

	colsqlen = 5;
	if (!ft_strncmp(str[*i], "{red}", 5))
	{
		store_write(pfs, "\x1b[31m", &colsqlen);
		return (5);
	}
	return (0);
}
