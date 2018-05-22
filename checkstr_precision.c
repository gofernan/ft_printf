/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 19:32:28 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:17:58 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		checkstr_precision_aff(const char *str, fstr_t *ptrfstring, int *auxshift)
{
	char *tmp;
	int i;

	i = 1;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	*auxshift = i - 1;
	//if (ptrfstring->precheck)
	//	return (1);
	if (!(tmp = (char *)malloc(sizeof(char) * i)))
		exit(EXIT_FAILURE);
	ft_strncpy(tmp, str + 1, i - 1);
	tmp[i - 1] = '\0';
	ptrfstring->precisionvalue = ft_atoi(tmp);
	free(tmp);
	return (1);
}

int		checkstr_precision(const char *str, fstr_t *ptrfstring, int *auxshift)
{
	if (*str == '.')
	{
		//if (!ptrfstring->precheck)
		ptrfstring->precision = 1;
		if (*(str + 1) == '*')
		{
			ptrfstring->precision_as = 1;
			*auxshift = 1;
			if (ptrfstring->precheck)
			{
				(ptrfstring->argordervalue)++;
				store_arglist(ptrfstring);
			}
			return (1);
		}
	}
	else
		return (0);
	if (*(str + 1) >= 48 && *(str + 1) <= 57)
		return (checkstr_precision_aff(str, ptrfstring, auxshift));
	else
	{
		//if (!ptrfstring->precheck)
			ptrfstring->precisionvalue = 0;
	}
	return (1);
}
