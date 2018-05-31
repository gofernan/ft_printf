/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_fwidth.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 17:39:27 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 18:56:12 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static int		checkstr_fwidth_asarg(const char *str, fstr_t *ptrfstring, int *auxshift, int *i)
{
	char	*tmp;
	int		tmpargorder;

	*i = 1;
	while (str[*i] >= 48 && str[*i] <= 57)
		(*i)++;
	if (str[*i] == '$')
	{
		*auxshift = *i;
		ptrfstring->fwidth_asarg = 1;
		if (!(tmp = malloc(sizeof(char) * (*i))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str + 1, *i - 1);
		tmp[*i - 1] = '\0';
		ptrfstring->fwidth_asargv = ft_atoi(tmp);
		free(tmp);
		tmpargorder = ptrfstring->argordervalue;
		ptrfstring->argordervalue = ptrfstring->fwidth_asargv;
		if (ptrfstring->precheck)
			store_arglist(ptrfstring);
		else
		{
			ptrfstring->fwidthvalue = ft_atoi(sel_arglist(ptrfstring)->str);
			if (ptrfstring->fwidthvalue < 0)
			{
				ptrfstring->flags[2] = 1;
				ptrfstring->fwidthvalue = -ptrfstring->fwidthvalue;
			}
		}
		ptrfstring->argordervalue = tmpargorder;
		return (1);
	}
	return (0);
}

static int		checkstr_fwidth_as(const char *str, fstr_t *ptrfstring, int *auxshift, int *i)
{
	if (str[*i] == '*')
	{
		ptrfstring->fwidth = 1;
		if (str[*i + 1] >= 48 && str[*i + 1] <= 57)
		{
			if (checkstr_fwidth_asarg(str, ptrfstring, auxshift, i))
				return (1);
		}
		if (!ptrfstring->argorder && !ptrfstring->precision_as && !ptrfstring->fwidth_as)
			(ptrfstring->argordervalue)++;
		if (ptrfstring->precheck)
		{
			store_arglist(ptrfstring);
		}
		else
		{
			ptrfstring->fwidthvalue = ft_atoi(sel_arglist(ptrfstring)->str);
			if (ptrfstring->fwidthvalue < 0)
			{
				ptrfstring->flags[2] = 1;
				ptrfstring->fwidthvalue = -ptrfstring->fwidthvalue;
			}
		}
		(ptrfstring->argordervalue)++;
		ptrfstring->fwidth_as = 1;
		return (1);
	}
	return (0);
}

int		checkstr_fwidth(const char *str, fstr_t *ptrfstring, int *auxshift)
{
	int		i;
	char	*tmp;

	i = 0;
	if (checkstr_fwidth_as(str, ptrfstring, auxshift, &i))
		return (1);
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] != '$' && i > 0)
	{
		*auxshift = i - 1;
		if (ptrfstring->precheck)
			return (1);
		if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str, i);
		tmp[i] = '\0';
		ptrfstring->fwidthvalue = ft_atoi(tmp);
		free(tmp);
		ptrfstring->fwidth = 1;
		return (1);
	}
	return (0);
}
