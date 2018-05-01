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

	if (!(s = va_arg(ap, char *)))
	{
		s = ft_strnew(6);
		ft_strcpy(s, "(null)");
		ptrfstring->converted = 1;
	}
	len = ft_strlen(s);
	//sconverted = NULL;
	//printf("len de string: %d\n", len);
	if (ptrfstring->precision && len > ptrfstring->precisionvalue)
		s = precisionf(s, &len, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
	   //sconverted = field_width(s, len, ptrfstring); // also checks flag 0 && flag -
	   s = field_width(s, &len, ptrfstring);
	//	ptrfstring->counter += write(1, sconverted, (ft_strlen(sconverted)));
	//if (ptrfstring->precision)
	ptrfstring->counter += write(1, s, len);
}
