/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:48:55 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 18:49:36 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*cconva(va_list ap, fstr_t *ptrfstring)
{
	char	a;
	char	*s;

	a = (char)va_arg(ap, int);
	if (!(s = ft_strnew(1)))
		exit(EXIT_FAILURE);
	ft_strncpy(s, &a, 1);
	return (s);
}

void		cconv(va_list ap, fstr_t *ptrfstring)
{
	char	a;
	char	*s;
	char	*sptr;
	int		len;

	sptr = sel_arglist(ptrfstring)->str;
	len = 1;
	s = malloc(sizeof(char) * (len + 1));
	ft_strcpy(s, sptr);
	ptrfstring->converted = 1;
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
