/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:39:31 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 19:51:37 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		initialize_struct(fstr_t *ptrfstring)
{
	int i;

	i = -1;
	ptrfstring->argorder = 0;
	ptrfstring->separator = 0;
	ptrfstring->fwidth = 0;
	ptrfstring->fwidth_as = 0;
	ptrfstring->fwidth_asarg = 0;
	ptrfstring->fwidth_asargv = 0;
	ptrfstring->fwidthvalue = 0;
	ptrfstring->precision = 0;
	ptrfstring->precision_as = 0;
	ptrfstring->precision_asarg = 0;
	ptrfstring->precision_asargv = 0;
	ptrfstring->precisionvalue = 0;
	while (++i < FLAGS_N)
		ptrfstring->flags[i] = 0;
	i = -1;
	while (++i < LENGTHM_N)
		ptrfstring->lengthmdf[i] = 0;
	ptrfstring->convesp = 0;
	ptrfstring->converted = 0;
	i = 0;
	//while (i < BUFF_SIZE)
	//	ptrfstring->buff[i++] = '\0';
}
