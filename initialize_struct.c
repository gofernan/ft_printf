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

void		initialize_struct(t_fstr *pfs)
{
	int i;

	i = -1;
	pfs->argo = 0;
	pfs->fwidth = 0;
	pfs->fwidth_as = 0;
	pfs->fwidth_asarg = 0;
	pfs->fwidth_asargv = 0;
	pfs->fwidthvalue = 0;
	pfs->prec = 0;
	pfs->prec_as = 0;
	pfs->prec_asarg = 0;
	pfs->prec_asargv = 0;
	pfs->precvalue = 0;
	pfs->lnchars = 0;
	while (++i < FLAGS_N)
		pfs->flags[i] = 0;
	i = -1;
	while (++i < LENGTHM_N)
		pfs->lengthmdf[i] = 0;
	pfs->conv = 0;
	pfs->converted = 0;
}
