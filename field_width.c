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

#include "includes/ft_printf.h"

char	*field_width(char *str, int *len, fstr_t *ptrfstring)
{
	char	*newstr;
	char	paddchar;

	if (!(newstr = (char *)malloc(sizeof(char) * (ptrfstring->fwidthvalue + 1))))
		exit(EXIT_FAILURE);
	if (ptrfstring->flags[1] && !(ptrfstring->flags[2]))
		paddchar = '0';
	else
		paddchar = ' ';
	if (!(ptrfstring->flags[2]))
	{
		ft_memset(newstr, paddchar, ptrfstring->fwidthvalue - *len);
		ft_strcpy(&newstr[ptrfstring->fwidthvalue - *len], str);
	}
	else
	{
		ft_strcpy(newstr, str);
		ft_memset(newstr + *len, paddchar, ptrfstring->fwidthvalue - *len);
	}
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ptrfstring->fwidthvalue;
	return (newstr);
}
