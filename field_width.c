/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 12:32:30 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/04 10:46:33 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char			*field_width(char *str, int len, fstr_t *ptrfstring)
{
	char *newstr;
	char paddchar;
	newstr = ft_strnew(ptrfstring->fwidthvalue);
	if (ptrfstring->flags[1] && !(ptrfstring->flags[2]))
		paddchar = '0';
	else
		paddchar = ' ';
	if (!(ptrfstring->flags[2]))
	{
	ft_memset(newstr, paddchar, ptrfstring->fwidthvalue - len);
	ft_strcat(newstr, str);
	}
	else
	{
		ft_strcat(newstr, str);
		ft_memset(ft_strchr(newstr, '\0'), paddchar, ptrfstring->fwidthvalue - len);
	}
	return (newstr);
}
