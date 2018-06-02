/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:00:38 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/15 16:35:52 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		fill_list(t_args *tmpargsl, t_fstr *pfs)
{
	int i;

	i = LENGTHM_N;
	tmpargsl->value = pfs->argov;
	if (pfs->conv)
	{
		tmpargsl->conv = pfs->conv;
		while (--i >= 0)
		{
			if (pfs->lengthmdf[i])
			{
				tmpargsl->mdf = i;
				break ;
			}
		}
		if (i == -1)
			tmpargsl->mdf = -1;
	}
	else
		tmpargsl->conv = 'd';
	tmpargsl->next = NULL;
}

void		init_listarg(t_args *tmpargsl)
{
	tmpargsl->value = 0;
	tmpargsl->conv = '\0';
	tmpargsl->mdf = -1;
	tmpargsl->str = NULL;
	tmpargsl->next = NULL;
	tmpargsl->validlen = 0;
}
void		store_arglist(t_fstr *pfs)
{
	t_args *tmpargsl;

	if (!pfs->ptrlargs)
	{
		if (!(pfs->ptrlargs = (t_args *)malloc(sizeof(t_args))))
			exit(EXIT_FAILURE);
		init_listarg(pfs->ptrlargs);
	}
	tmpargsl = pfs->ptrlargs;
	while (tmpargsl)
	{
		if (!tmpargsl->value)
		{
			fill_list(tmpargsl, pfs);
			break ;
		}
		else if (tmpargsl->value == pfs->argov)
			break ;
		else
		{
			if (!tmpargsl->next)
			{
				if (!(tmpargsl->next = (t_args *)malloc(sizeof(t_args))))
					exit(EXIT_FAILURE);
				init_listarg(tmpargsl->next);
				fill_list(tmpargsl->next, pfs);
			}
			tmpargsl = tmpargsl->next;
		}
	}
	/*}
	if (!tmpargsl)
	{
		if (!(tmpargsl = (t_args *)malloc(sizeof(t_args))))
			exit(EXIT_FAILURE);
		fill_list(tmpargsl, pfs);
	}*/
}
