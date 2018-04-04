/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/04 11:35:32 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
//flag # no effect
//- override 0
int	sconv(va_list ap, fstr_t *ptrfstring)
{
	char *s;
	char *sconverted;
	int counter;
	int len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	sconverted = NULL;
	printf("len de string: %d\n", len);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
	{
	   sconverted = field_width(s, len, ptrfstring); // also checks flag 0 && flag -
		counter = write(1, sconverted, (ft_strlen(sconverted)));
	}
	else
		counter = write(1, s, len);
	return (counter);
}
