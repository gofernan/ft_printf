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
	//if (!ptrfstring->argorder)
	//	tmpargsl->value = (ptrfstring->argordervalue)++;
	//else
	tmpargsl->value = ptrfstring->argordervalue;
	tmpargsl->convesp = ptrfstring->convesp;
	if ((ptrfstring->convesp == 's' && ptrfstring->lengthmdf[2]) || ptrfstring->convesp == 'S'
			|| ptrfstring->convesp == 'C')
	{
		tmpargsl->precision = ptrfstring->precision;
		tmpargsl->precisionvalue = ptrfstring->precisionvalue;
		if (ptrfstring->convesp == 's' && ptrfstring->lengthmdf[2])
			tmpargsl->mdf = 2;
	}
	/*only implemented to s conversor*/
	/*take care because other length modifiers may be introduced */
	else
	{
		while (--i >= 0)
		{
			if (ptrfstring->lengthmdf[i])
			{
				tmpargsl->mdf = i;
				break ;
			}
		}
	}
	if (i == -1)
		tmpargsl->mdf = -1;
	tmpargsl->next = NULL;
}

void		init_listarg(t_args *tmpargsl)
{
	tmpargsl->value = 0;
	tmpargsl->convesp = '\0';
	tmpargsl->mdf = 0;
	tmpargsl->str = NULL;
	tmpargsl->next = NULL;
	tmpargsl->precision = 0;
	tmpargsl->precisionvalue = 0;
}
void		check_list(fstr_t *ptrfstring)
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

void		store_arglist(fstr_t *ptrfstring)
{

	//if (ptrfstring->convesp == 's' && !(ptrfstring->lengthmdf[2]))
		check_list(ptrfstring);
}
