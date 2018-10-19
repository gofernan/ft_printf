/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_inside.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:36:42 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/04 11:16:28 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		conversion(const char *str, t_fstr *pfs, int *i)
{
	if (convsp(&str[*i], pfs) && !pfs->argo && !pfs->fwidth_as && !pfs->prec_as)
		(pfs->argov)++;
	if (pfs->precheck)
		store_arglist(pfs);
	else
		conversors(str, pfs, i);
	if (pfs->counter != -1)
	{
		initialize_struct(pfs);
		return (0);
	}
	return (1);
}

int				checkstr_inside(const char *str, t_fstr *pfs, int *i)
{
	int aux;

	aux = 0;
	if (checkstr_argorder(&str[*i], pfs, &aux))
	{
		if (!pfs->argov)
		{
			*i += aux - 2;
			initialize_struct(pfs);
			return (0);
		}
		*i += aux - 1;
	}
	else if (checkstr_flags(&str[*i], pfs))
		;
	else if (checkstr_fwidth(&str[*i], pfs, &aux))
		*i += aux;
	else if (checkstr_prec(&str[*i], pfs, &aux))
		*i += aux;
	else if (checkmdfs(str, pfs, i))
		;
	else if (!(conversion(str, pfs, i)))
		return (0);
	return (1);
}
