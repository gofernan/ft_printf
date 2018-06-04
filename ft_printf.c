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

static void		init_prestore(t_fstr *pfs)
{
	pfs->ptrlargs = NULL;
	pfs->counter = 0;
	pfs->argov = 0;
	pfs->buffi = 0;
	pfs->lnchars = 0;
	pfs->precheck = 0;
	pfs->buffsize = 1000;
	if (!(pfs->buff = (char *)malloc(sizeof(char) * (pfs->buffsize + 1))))
		exit(EXIT_FAILURE);
}

static void		init_poststore(t_fstr *pfs)
{
	int i;

	i = -1;
	pfs->prec = 0;
	pfs->precvalue = 0;
	pfs->precheck = 0;
	pfs->argov = 0;
	pfs->argo = 0;
	pfs->conv = 0;
	while (++i < LENGTHM_N)
		pfs->lengthmdf[i] = 0;
}

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	t_fstr		fstring;
	t_fstr		*pfs;

	va_start(ap, str);
	pfs = &fstring;
	init_prestore(pfs);
	initialize_struct(pfs);
	checkstr_allargs(str, pfs, ap);
	if (pfs->ptrlargs)
		retr_arglist(ap, pfs);
	init_poststore(pfs);
	checkstr(str, pfs, ap);
	if (pfs->counter != -1)
		pfs->counter += write(1, pfs->buff, pfs->buffi);
	else
		write(1, pfs->buff, pfs->buffi - pfs->lnchars);
	va_end(ap);
	ft_strdel(&pfs->buff);
	free_struct(pfs);
	return (pfs->counter);
}
