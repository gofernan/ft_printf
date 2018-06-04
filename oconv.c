/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:39:57 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 17:52:39 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*omdfs(va_list ap, t_args *tmpargsl)
{
	char *s;

	if (tmpargsl->conv == 'O')
		s = ft_uitoab(va_arg(ap, unsigned long), 8, 0);
	else if (tmpargsl->mdf == 7)
		s = ft_uitoab(va_arg(ap, u_quad_t), 8, 0);
	else if (tmpargsl->mdf == 6)
		s = ft_uitoab(va_arg(ap, size_t), 8, 0);
	else if (tmpargsl->mdf == 5)
		s = ft_uitoab(va_arg(ap, ptrdiff_t), 8, 0);
	else if (tmpargsl->mdf == 4)
		s = ft_uitoab(va_arg(ap, uintmax_t), 8, 0);
	else if (tmpargsl->mdf == 3)
		s = ft_uitoab(va_arg(ap, unsigned long long), 8, 0);
	else if (tmpargsl->mdf == 2)
		s = ft_uitoab(va_arg(ap, unsigned long), 8, 0);
	else if (tmpargsl->mdf == 1)
		s = ft_uitoab((unsigned short)va_arg(ap, unsigned int), 8, 0);
	else if (tmpargsl->mdf == 0)
		s = ft_uitoab((unsigned char)va_arg(ap, unsigned int), 8, 0);
	else
		s = ft_uitoab(va_arg(ap, unsigned int), 8, 0);
	if (!s)
		exit(EXIT_FAILURE);
	return (s);
}

static char		*all_conv(t_fstr *pfs, char *s, int *len)
{
	if (pfs->flags[0])
		s = flag_sharp(s, len, pfs);
	if (pfs->prec && pfs->precvalue > *len)
		s = precdigits(s, len, 0, pfs);
	if (pfs->fwidth && *len < pfs->fwidthvalue)
		s = field_width_num(s, len, pfs);
	store_write(pfs, s, len);
	return (s);
}

void		oconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;

	sptr = sel_arglist(pfs)->str;
	if ((pfs->prec && pfs->precvalue == 0 && !ft_strcmp(sptr, "0"))
		|| (!ft_strcmp(sptr, "0") && pfs->flags[0]))
	{
		s = ft_strnew(0);
		len = 0;
	}
	else
	{
		len = ft_strlen(sptr);
		s = malloc(sizeof(char) * (len + 1));
		ft_strcpy(s, sptr);
	}
	pfs->converted = 1;
	s = all_conv(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
