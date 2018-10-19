/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:35:16 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 17:57:32 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*umdfs(va_list ap, t_args *tmpargsl)
{
	char *s;

	if (tmpargsl->conv == 'U')
		s = ft_uitoa(va_arg(ap, unsigned long));
	else if (tmpargsl->mdf == 7)
		s = ft_uitoa(va_arg(ap, u_quad_t));
	else if (tmpargsl->mdf == 6)
		s = ft_uitoa(va_arg(ap, size_t));
	else if (tmpargsl->mdf == 5)
		s = ft_uitoa(va_arg(ap, ptrdiff_t));
	else if (tmpargsl->mdf == 4)
		s = ft_uitoa(va_arg(ap, uintmax_t));
	else if (tmpargsl->mdf == 3)
		s = ft_uitoa(va_arg(ap, unsigned long long));
	else if (tmpargsl->mdf == 2)
		s = ft_uitoa(va_arg(ap, unsigned long));
	else if (tmpargsl->mdf == 1)
		s = ft_uitoa((unsigned short)va_arg(ap, unsigned int));
	else if (tmpargsl->mdf == 0)
		s = ft_uitoa((unsigned char)va_arg(ap, unsigned int));
	else
		s = ft_uitoa(va_arg(ap, unsigned int));
	if (!s)
		exit(EXIT_FAILURE);
	return (s);
}

void		uconv(t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;

	sptr = sel_arglist(pfs)->str;
	if (pfs->prec && pfs->precvalue == 0 && !ft_strcmp(sptr, "0"))
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
	if (pfs->prec && pfs->precvalue > len)
		s = precdigits(s, &len, 0, pfs);
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width_num(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
