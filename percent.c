/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:21:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:22:22 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		percent(char a, fstr_t *ptrfstring)
{
	char	*s;
	int		len;

	len = 1;
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		exit(EXIT_FAILURE);
	ft_strncpy(s, &a, 1);
	*(s + 1) = '\0';
	ptrfstring->converted = 1;
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
