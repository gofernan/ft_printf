/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/03 19:13:57 by gofernan         ###   ########.fr       */
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

	s = va_arg(ap, char *);
	sconverted = NULL;
	if (ptrfstring->fwidth)
	   sconverted = field_width(s, ptrfstring);

	counter = write(1, sconverted, (ft_strlen(sconverted) + 1));
	return (counter);
}
