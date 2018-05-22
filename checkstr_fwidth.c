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

int		checkstr_fwidth_as(const char *str, fstr_t *ptrfstring, int *auxshift, int *i)
{
	if (str[*i] == '*')
	{
		if (ptrfstring->precheck)
		{
			(ptrfstring->argordervalue)++;
			store_arglist(ptrfstring);
		}
		ptrfstring->fwidth_as = 1;
		ptrfstring->fwidth = 1;
		(*auxshift)++;
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
		*auxshift = i;
		if (ptrfstring->precheck)
			return (1);
		if (ptrfstring->fwidth_as)
		{
			ptrfstring->fwidth_as = 0;
			(ptrfstring->argordervalue)++;
		}
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
