/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_sharp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:31:06 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:34:13 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static char			*flag_sharp_o(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (*len + 2))))
		exit(EXIT_FAILURE);
	*newstr = '0';
	ft_strcpy(newstr + 1, str);
	*len += 1;
	return (newstr);
}

static char			*flag_sharp_x(char *str, int *len, fstr_t *ptrfstring)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (*len + 3))))
		exit(EXIT_FAILURE);
	if (ptrfstring->convesp == 'x' || ptrfstring->convesp == 'p')
		ft_strcpy(newstr, "0x");
	else
		ft_strcpy(newstr, "0X");
	ft_strcpy(newstr + 2, str);
	*len += 2;
	return (newstr);
}

char				*flag_sharp(char *str, int *len, fstr_t *ptrfstring)
{
	char	*newstr;

	if (ptrfstring->convesp == 'x' || ptrfstring->convesp == 'X' || ptrfstring->convesp == 'p')
		newstr = flag_sharp_x(str, len, ptrfstring);
	else if (ptrfstring->convesp == 'o' || ptrfstring->convesp == 'O')
		newstr = flag_sharp_o(str, len, ptrfstring);
	if (ptrfstring->converted)
		ft_strdel(&str);
	else
		ptrfstring->converted = 1;
	return (newstr);
}
