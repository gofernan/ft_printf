/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisionfw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:38:43 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:38:56 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*precisionfw(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	while ((((unsigned char)str[ptrfstring->precisionvalue]) >> 6) == 0x02)
		ptrfstring->precisionvalue--;
	if (!(newstr = ft_strnew(ptrfstring->precisionvalue)))
		exit (EXIT_FAILURE);
	ft_strncpy(newstr, str, ptrfstring->precisionvalue);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	*len = ft_strlen(newstr);
	return (newstr);
}
