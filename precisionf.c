/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisionf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:40:16 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:40:25 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*precisionf(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = ft_strnew(ptrfstring->precisionvalue)))
		exit(EXIT_FAILURE);
	ft_strncpy(newstr, str, ptrfstring->precisionvalue);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
