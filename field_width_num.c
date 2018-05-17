/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width_num.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:35:46 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:15:32 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void		fwaux(char *str, char *newstr, int *len, fstr_t *ptrfstring)
{
	if (ptrfstring->flags[1] && !ptrfstring->precision)
	{
		if (*str == '-' || *str == ' ' || *str == '+')
		{
			*newstr = *str;
			ft_memset(newstr + 1, '0', ptrfstring->fwidthvalue - *len);
			//ft_strcat(newstr, str + 1);
			ft_strcpy(&newstr[ptrfstring->fwidthvalue - *len + 1], str + 1);
		}
		else if (*(str + 1) == 'X' || *(str + 1) == 'x')
		{
			ft_strncpy(newstr, str, 2);
			ft_memset(newstr + 2, '0', ptrfstring->fwidthvalue - *len);
			//ft_strcat(newstr, str + 2);
			ft_strcpy(&newstr[ptrfstring->fwidthvalue - *len + 2], str + 2);
		}
		else
		{
			ft_memset(newstr, '0', ptrfstring->fwidthvalue - *len);
			//ft_strcat(newstr, str);
			ft_strcpy(&newstr[ptrfstring->fwidthvalue - *len], str);
		}
	}
	else
	{
		ft_memset(newstr, ' ', ptrfstring->fwidthvalue - *len);
		//ft_strcat(newstr, str);
		ft_strcpy(&newstr[ptrfstring->fwidthvalue - *len], str);
	}
}

char			*field_width_num(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	//if (!(newstr = ft_strnew(ptrfstring->fwidthvalue)))
	//	exit(EXIT_FAILURE);
	if (!(newstr = (char *)malloc(sizeof(char) * (ptrfstring->fwidthvalue + 1))))
		exit(EXIT_FAILURE);
	if (ptrfstring->flags[2])
	{
		ft_strncpy(newstr, str, *len);
		//ft_memset(ft_strchr(newstr, '\0'), ' ', ptrfstring->fwidthvalue - *len);
		ft_memset(&newstr[*len], ' ', ptrfstring->fwidthvalue - *len);
		newstr[ptrfstring->fwidthvalue] = '\0';
	}
	else
		fwaux(str, newstr, len, ptrfstring);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	//*len = ft_strlen(newstr);
	*len = ptrfstring->fwidthvalue;
	return (newstr);
}
