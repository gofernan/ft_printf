/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_argorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 12:10:45 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/20 18:34:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int			checkstr_argorder(const char *str, fstr_t *ptrfstring)
{
	int i;

	i = 0;
	printf("Dentro de checkstr_argorder\n");
	printf("str =%s\n", str);
	while (str[i] >= 48 && str[i] <= 57)
	{
		printf("Es un numero\n");
		i++;
	}
	if (str[i] == '$' && i > 0)
	{
		printf("Es un dollar\n");
		ptrfstring->argordervalue = ft_memalloc(i + 1);
		ft_strncpy(ptrfstring->argordervalue, str, i);
		ptrfstring->argorder = 1;
		return (1);
	}
	return (0);
}
