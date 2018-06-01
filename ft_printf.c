/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 22:49:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:10:51 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	fstr_t		fstring;
	fstr_t		*ptrfstring;
	int			i;

	i = -1;
	va_start(ap, str);
	ptrfstring = &fstring;
	ptrfstring->ptrlargs = NULL;
	ptrfstring->counter = 0;
	ptrfstring->argordervalue = 0;
	ptrfstring->buffi = 0;
	ptrfstring->lnchars = 0;
	ptrfstring->precheck = 0;
	//ptrfstring->argorder = 0;
	//ptrfstring->buffsize = 1000;
	//ptrfstring->buff = (char *)malloc(sizeof(char) * (ptrfstring->buffsize + 1));
	initialize_struct(ptrfstring);
	checkstr_allargs(str, ptrfstring, ap);
	if (ptrfstring->ptrlargs)
		retr_arglist(ap, ptrfstring);
	ptrfstring->precision = 0;
	ptrfstring->precisionvalue = 0;
	ptrfstring->precheck = 0;
	ptrfstring->argordervalue = 0;
	ptrfstring->argorder = 0;
	ptrfstring->convesp = 0;
	while (++i < LENGTHM_N)
		ptrfstring->lengthmdf[i] = 0;
	checkstr(str, ptrfstring, ap);
	if (ptrfstring->counter != -1)
		ptrfstring->counter += write(1, ptrfstring->buff, ptrfstring->buffi);
	else
		write(1, ptrfstring->buff, ptrfstring->buffi - ptrfstring->lnchars);
	va_end(ap);
	free_struct(ptrfstring);
	return (ptrfstring->counter);
}
