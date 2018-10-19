/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precdigits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:39:10 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:25:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*pluspr(char *str, int *len, int plusp, t_fstr *pfs)
{
	char	*newstr;

	newstr = NULL;
	if (!(newstr = ft_strnew(pfs->precvalue + plusp)))
		exit(EXIT_FAILURE);
	if (plusp == 1)
		ft_memset(newstr, '-', 1);
	else if (plusp == 2)
	{
		if (pfs->conv == 'x' || pfs->conv == 'p')
			ft_strcpy(newstr, "0x");
		else
			ft_strcpy(newstr, "0X");
	}
	ft_memset(newstr + plusp, '0', pfs->precvalue + plusp - *len);
	ft_strcat(newstr, str + plusp);
	return (newstr);
}

char			*precdigits(char *str, int *len, int plusp, t_fstr *pfs)
{
	char	*newstr;

	if (plusp)
		newstr = pluspr(str, len, plusp, pfs);
	else
	{
		if (!(newstr = ft_strnew(pfs->precvalue)))
			exit(EXIT_FAILURE);
		ft_memset(newstr, '0', pfs->precvalue - *len);
		ft_strcat(newstr, str);
	}
	if (pfs->converted)
		ft_strdel(&str);
	else
		pfs->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
