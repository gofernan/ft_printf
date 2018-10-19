/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precfw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:38:43 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:25:48 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*precfw(char *str, int *len, t_fstr *pfs)
{
	char	*newstr;

	while ((((unsigned char)str[pfs->precvalue]) >> 6) == 0x02)
		pfs->precvalue--;
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
