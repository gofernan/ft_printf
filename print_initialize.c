/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_initialize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 23:18:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/23 21:14:04 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		print_initialize(fstr_t *ptrfstring)
{
	int i;

	i = -1;
	printf("argorder: %d\n", ptrfstring->argorder);
	while (++i < FLAGS_N)
		printf("flags[%d]: %d\n", i, ptrfstring->flags[i]);
	printf("separator: %d\n", ptrfstring->separator);
	printf("fwidth: %d\n", ptrfstring->fwidth);
	printf("precision %d\n", ptrfstring->precision);
	i = -1;
	while (++i < LENGTHM_N)
		printf("lenghtmdf[%d]: %d\n", i, ptrfstring->lengthmdf[i]);
	printf("convesp: %c\n", ptrfstring->convesp);
	printf("argordervalue = %s\n", ptrfstring->argordervalue);
	printf("fwidthvalue = %d\n", ptrfstring->fwidthvalue);
	printf("precisionvalue = %s\n", ptrfstring->precisionvalue);
	printf("counter = %d", ptrfstring->counter);
}
