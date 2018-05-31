/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:00:38 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/15 16:35:52 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		fill_list(t_args *tmpargsl, fstr_t *ptrfstring)
{
	int i;

	i = LENGTHM_N;
	tmpargsl->value = ptrfstring->argordervalue;
	if (ptrfstring->convesp)
	{
		tmpargsl->convesp = ptrfstring->convesp;
		while (--i >= 0)
		{
			if (ptrfstring->lengthmdf[i])
			{
				tmpargsl->mdf = i;
				break ;
			}
		}
		if (i == -1)
			tmpargsl->mdf = -1;
	}
	else
		tmpargsl->convesp = 'd';
	tmpargsl->next = NULL;
}

void		init_listarg(t_args *tmpargsl)
{
	tmpargsl->value = 0;
	tmpargsl->convesp = '\0';
	tmpargsl->mdf = -1;
	tmpargsl->str = NULL;
	tmpargsl->next = NULL;
	tmpargsl->validlen = 0;
}
void		store_arglist(fstr_t *ptrfstring)
{
	t_args *tmpargsl;

	if (!ptrfstring->ptrlargs)
	{
		if (!(ptrfstring->ptrlargs = (t_args *)malloc(sizeof(t_args))))
			exit(EXIT_FAILURE);
		init_listarg(ptrfstring->ptrlargs);
	}
	tmpargsl = ptrfstring->ptrlargs;
	while (tmpargsl)
	{
		if (!tmpargsl->value)
		{
			fill_list(tmpargsl, ptrfstring);
			break ;
		}
		else if (tmpargsl->value == ptrfstring->argordervalue)
			break ;
		else
		{
			if (!tmpargsl->next)
			{
				if (!(tmpargsl->next = (t_args *)malloc(sizeof(t_args))))
					exit(EXIT_FAILURE);
				init_listarg(tmpargsl->next);
				fill_list(tmpargsl->next, ptrfstring);
			}
			tmpargsl = tmpargsl->next;
		}
	}
	/*}
	if (!tmpargsl)
	{
		if (!(tmpargsl = (t_args *)malloc(sizeof(t_args))))
			exit(EXIT_FAILURE);
		fill_list(tmpargsl, ptrfstring);
	}*/
}
