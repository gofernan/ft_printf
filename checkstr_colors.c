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

static int	checkstr_storecolor(char *s, t_fstr *pfs, int reallen)
{
	int len;

	len = 5;
	store_write(pfs, s, &len);
	return (reallen);
}

int			checkstr_colors(const char *str, t_fstr *pfs, int *i)
{
	if (!ft_strncmp(&str[*i], "black}", 6))
		return (checkstr_storecolor("\x1b[30m", pfs, 6));
	else if (!ft_strncmp(&str[*i], "red}", 4))
		return (checkstr_storecolor("\x1b[31m", pfs, 4));
	else if (!ft_strncmp(&str[*i], "green}", 6))
		return (checkstr_storecolor("\x1b[32m", pfs, 6));
	else if (!ft_strncmp(&str[*i], "yellow}", 7))
		return (checkstr_storecolor("\x1b[33m", pfs, 7));
	else if (!ft_strncmp(&str[*i], "blue}", 5))
		return (checkstr_storecolor("\x1b[34m", pfs, 5));
	else if (!ft_strncmp(&str[*i], "magenta}", 8))
		return (checkstr_storecolor("\x1b[35m", pfs, 8));
	else if (!ft_strncmp(&str[*i], "cyan}", 5))
		return (checkstr_storecolor("\x1b[36m", pfs, 5));
	else if (!ft_strncmp(&str[*i], "white}", 6))
		return (checkstr_storecolor("\x1b[37m", pfs, 6));
	else if (!ft_strncmp(&str[*i], "eoc}", 4))
		return (checkstr_storecolor("\x1b[39m", pfs, 4));
	return (0);
}
