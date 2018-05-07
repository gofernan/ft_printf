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

int		checkstr_precision(const char *str, fstr_t *ptrfstring, int *auxshift)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str[i] == '.')
		ptrfstring->precision = 1;
	else
		return (0);
	if (str[i + 1] >= 48 && str[i + 1] <= 57)
	{
		i++;
		while (str[i] >= 48 && str[i] <= 57)
			i++;
		tmp = ft_strnew(i);
		ft_strncpy(tmp, str + 1, i - 1);
		*auxshift = ft_strlen(tmp);
		ptrfstring->precisionvalue = ft_atoi(tmp);
		free(tmp);
		return (1);
	}
	else
		ptrfstring->precisionvalue = 0;
	return (1);
}
