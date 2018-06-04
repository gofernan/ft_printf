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

char		*cconva(va_list ap)
{
	char	a;
	char	*s;

	a = (char)va_arg(ap, int);
	if (!(s = ft_strnew(1)))
		exit(EXIT_FAILURE);
	ft_strncpy(s, &a, 1);
	return (s);
}

void		cconv(t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;

	sptr = sel_arglist(pfs)->str;
	len = 1;
	s = malloc(sizeof(char) * (len + 1));
	ft_strcpy(s, sptr);
	pfs->converted = 1;
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
