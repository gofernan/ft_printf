/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:32:30 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:19:34 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*field_width(char *str, int *len, t_fstr *pfs)
{
	char	*newstr;
	char	paddchar;

	if (!(newstr = (char *)malloc(sizeof(char) * (pfs->fwidthvalue + 1))))
		exit(EXIT_FAILURE);
	if (pfs->flags[1] && !(pfs->flags[2]))
		paddchar = '0';
	else
		paddchar = ' ';
	if (!(pfs->flags[2]))
	{
		ft_memset(newstr, paddchar, pfs->fwidthvalue - *len);
		ft_strcpy(&newstr[pfs->fwidthvalue - *len], str);
	}
	else
	{
		ft_strcpy(newstr, str);
		ft_memset(newstr + *len, paddchar, pfs->fwidthvalue - *len);
	}
	if (pfs->converted)
		ft_strdel(&str);
	else
		pfs->converted = 1;
	*len = pfs->fwidthvalue;
	return (newstr);
}
