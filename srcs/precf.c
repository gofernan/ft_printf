/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:40:16 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:40:25 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*precf(char *str, int *len, t_fstr *pfs)
{
	char *newstr;

	if (!(newstr = ft_strnew(pfs->precvalue)))
		exit(EXIT_FAILURE);
	ft_strncpy(newstr, str, pfs->precvalue);
	if (pfs->converted)
		ft_strdel(&str);
	else
		pfs->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
