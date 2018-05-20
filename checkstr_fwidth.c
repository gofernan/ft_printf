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

int		checkstr_fwidth(const char *str, fstr_t *ptrfstring, int *auxshift)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] != '$' && i > 0)
	{
		*auxshift = i;
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
