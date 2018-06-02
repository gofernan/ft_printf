/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:37:46 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:37:48 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*flag_space(char *str, int *len, t_fstr *pfs)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (*len + 2))))
		exit(EXIT_FAILURE);
	*newstr = ' ';
	ft_strcpy(newstr + 1, str);
	if (pfs->converted)
		ft_strdel(&str);
	else
		pfs->converted = 1;
	*len += 1;
	return (newstr);
}
