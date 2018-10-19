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

#include "../includes/ft_printf.h"

static char			*flag_sharp_o(char *str, int *len)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (*len + 2))))
		exit(EXIT_FAILURE);
	*newstr = '0';
	ft_strcpy(newstr + 1, str);
	*len += 1;
	return (newstr);
}

static char			*flag_sharp_x(char *str, int *len, t_fstr *pfs)
{
	char *newstr;

	if (!(newstr = (char *)malloc(sizeof(char) * (*len + 3))))
		exit(EXIT_FAILURE);
	if (pfs->conv == 'x' || pfs->conv == 'p')
		ft_strcpy(newstr, "0x");
	else
		ft_strcpy(newstr, "0X");
	ft_strcpy(newstr + 2, str);
	*len += 2;
	return (newstr);
}

char				*flag_sharp(char *str, int *len, t_fstr *pfs)
{
	char	*newstr;

	newstr = NULL;
	if (pfs->conv == 'x' || pfs->conv == 'X' || pfs->conv == 'p')
		newstr = flag_sharp_x(str, len, pfs);
	else if (pfs->conv == 'o' || pfs->conv == 'O')
		newstr = flag_sharp_o(str, len);
	if (pfs->converted)
		ft_strdel(&str);
	else
		pfs->converted = 1;
	return (newstr);
}
