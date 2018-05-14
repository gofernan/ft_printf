/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisiondigits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:39:10 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:25:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char		*pluspr(char *str, int *len, int plusp, fstr_t *ptrfstring)
{
	char	*newstr;

	newstr = NULL;
	if (!(newstr = ft_strnew(ptrfstring->precisionvalue + plusp)))
		exit(EXIT_FAILURE);
	if (plusp == 1)
		ft_memset(newstr, '-', 1);
	else if (plusp == 2)
	{
		if (ptrfstring->convesp == 'x' || ptrfstring->convesp == 'p')
			ft_strcpy(newstr, "0x");
		else
			ft_strcpy(newstr, "0X");
	}
	ft_memset(newstr + plusp, '0', ptrfstring->precisionvalue + plusp - *len);
	ft_strcat(newstr, str + plusp);
	return (newstr);
}

char			*precisiondigits(char *str, int *len, int plusp, fstr_t *ptrfstring)
{
	char	*newstr;

	if (plusp)
		newstr = pluspr(str, len, plusp, ptrfstring);
	else
	{
		if (!(newstr = ft_strnew(ptrfstring->precisionvalue)))
			exit(EXIT_FAILURE);
		ft_memset(newstr, '0', ptrfstring->precisionvalue - *len);
		ft_strcat(newstr, str);
	}
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
