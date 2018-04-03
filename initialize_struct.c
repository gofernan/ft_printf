/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 19:39:31 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/03 19:53:27 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		initialize_struct(fstr_t *ptrfstring)
{
	int i;

	i = -1;
	ptrfstring->argorder = 0;
	ptrfstring->argordervalue = NULL;
	ptrfstring->separator = 0;
	ptrfstring->fwidth = 0;
	ptrfstring->fwidthvalue = 0;
	ptrfstring->precision = 0;
	ptrfstring->precisionvalue = NULL;
	while (++i < FLAGS_N)
		ptrfstring->flags[i] = 0;
	i = -1;
	while (++i < LENGTHM_N)
		ptrfstring->lengthmdf[i] = 0;
	ptrfstring->convesp = 0;
}
