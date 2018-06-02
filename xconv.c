/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:33:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:26:36 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*xmdfs(va_list ap, t_args *tmpargsl)
{
	int		altform;
	char	*s;

	altform = (tmpargsl->conv == 'X') ? 1 : 0;
	if (tmpargsl->mdf == 7)
		s = ft_uimaxtoa_base(va_arg(ap, u_quad_t), 16, altform);
	else if (tmpargsl->mdf == 6)
		s = ft_uimaxtoa_base(va_arg(ap, size_t), 16, altform);
	else if (tmpargsl->mdf == 5)
		s = ft_uimaxtoa_base(va_arg(ap, ptrdiff_t), 16, altform);
	else if (tmpargsl->mdf == 4)
		s = ft_uimaxtoa_base(va_arg(ap, uintmax_t), 16, altform);
	else if (tmpargsl->mdf == 3)
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long long), 16, altform);
	else if (tmpargsl->mdf == 2)
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long), 16, altform);
	else if (tmpargsl->mdf == 1)
		s = ft_uimaxtoa_base((unsigned short)va_arg(ap, unsigned int), 16, altform);
	else if (tmpargsl->mdf == 0)
		s = ft_uimaxtoa_base((unsigned char)va_arg(ap, unsigned int), 16, altform);
	else
		s = ft_uimaxtoa_base(va_arg(ap, unsigned int), 16, altform);
	if (!s)
		exit(EXIT_FAILURE);
	return (s);
}

void			xconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;
	int		plusp;

	plusp = 0;
	sptr = sel_arglist(pfs)->str;
	if (pfs->prec && pfs->precvalue == 0 && !ft_strcmp(sptr, "0"))
	{
		//*s = '\0';
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
	if (pfs->flags[0] && ft_strcmp(s, "0") && len > 0)
	{
		s = flag_sharp(s, &len, pfs);
		plusp = 2;
	}
	if (pfs->prec && pfs->precvalue > (len - plusp))
		s = precdigits(s, &len, plusp, pfs);
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width_num(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
