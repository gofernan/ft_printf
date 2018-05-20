/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_argorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:10:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 19:51:20 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_argorder(const char *str, fstr_t *ptrfstring, int *auxshift)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] >= 48 && str[i] <= 57)
		i++;
	if (str[i] == '$' && i > 0)
	{
		if (!(tmp = malloc(sizeof(char) * (i + 1))))
			exit(EXIT_FAILURE);
		ft_strncpy(tmp, str, i);
		tmp[i] = '\0';
		*auxshift = i + 1;
		ptrfstring->argordervalue = ft_atoi(tmp);
		free(tmp);
		ptrfstring->argorder = 1;
		return (1);
	}
	return (0);
}
