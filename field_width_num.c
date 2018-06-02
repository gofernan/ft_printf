/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:35:46 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:14:29 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		fwaux(char *str, char *newstr, int *len, t_fstr *pfs)
{
	if (pfs->flags[1] && !pfs->prec)
	{
		if (*str == '-' || *str == ' ' || *str == '+')
		{
			*newstr = *str;
			ft_memset(newstr + 1, '0', pfs->fwidthvalue - *len);
			ft_strcpy(&newstr[pfs->fwidthvalue - *len + 1], str + 1);
		}
		else if (*(str + 1) == 'X' || *(str + 1) == 'x')
		{
			ft_strncpy(newstr, str, 2);
			ft_memset(newstr + 2, '0', pfs->fwidthvalue - *len);
			ft_strcpy(&newstr[pfs->fwidthvalue - *len + 2], str + 2);
		}
		else
		{
			ft_memset(newstr, '0', pfs->fwidthvalue - *len);
			ft_strcpy(&newstr[pfs->fwidthvalue - *len], str);
		}
	}
	else
	{
		ft_memset(newstr, ' ', pfs->fwidthvalue - *len);
		ft_strcpy(&newstr[pfs->fwidthvalue - *len], str);
	}
}

char			*field_width_num(char *str, int *len, t_fstr *pfs)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (pfs->fwidthvalue + 1))))
		exit(EXIT_FAILURE);
	if (pfs->flags[2])
	{
		ft_strncpy(newstr, str, *len);
		ft_memset(&newstr[*len], ' ', pfs->fwidthvalue - *len);
		newstr[pfs->fwidthvalue] = '\0';
	}
	else
		fwaux(str, newstr, len, pfs);
	if (pfs->converted)
		ft_strdel(&str);
	else
		pfs->converted = 1;
	*len = pfs->fwidthvalue;
	return (newstr);
}
