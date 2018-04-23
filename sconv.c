/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/23 21:14:12 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
//flag # no effect
//- override 0
void	sconv(va_list ap, fstr_t *ptrfstring)
{
	char *s;
	//char *sconverted;
	int len;

	s = va_arg(ap, char *);
	len = ft_strlen(s);
	//sconverted = NULL;
	printf("len de string: %d\n", len);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
	   //sconverted = field_width(s, len, ptrfstring); // also checks flag 0 && flag -
	   s = field_width(s, len, ptrfstring);
	//	ptrfstring->counter += write(1, sconverted, (ft_strlen(sconverted)));
	//if (ptrfstring->precision)

	else
		ptrfstring->counter += write(1, s, len);
}
