/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 19:19:55 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 19:21:43 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*dimdfs(va_list ap, t_args *tmpargsl)
{
	char *s;

	if (tmpargsl->conv == 'D')
		s = ft_ltoa(va_arg(ap, long int));
	else if (tmpargsl->mdf == 7)
		s = ft_imaxtoa(va_arg(ap, quad_t));
	else if (tmpargsl->mdf == 6)
		s = ft_imaxtoa(va_arg(ap, size_t));
	else if (tmpargsl->mdf == 5)
		s = ft_uimaxtoa(va_arg(ap, ptrdiff_t));
	else if (tmpargsl->mdf == 4)
		s = ft_imaxtoa(va_arg(ap, intmax_t));
	else if (tmpargsl->mdf == 3)
		s = ft_lltoa(va_arg(ap, long long));
	else if (tmpargsl->mdf == 2)
		s = ft_ltoa(va_arg(ap, long));
	else if (tmpargsl->mdf == 1)
		s = ft_itoa((short)va_arg(ap, int));
	else if (tmpargsl->mdf == 0)
		s = ft_itoa((signed char)va_arg(ap, int));
	else
		s = ft_itoa(va_arg(ap, int));
	if (!s)
		exit(EXIT_FAILURE);
	return (s);
}

void		diconv(va_list ap, t_fstr *pfs)
{
	char	*s;
	char	*sptr;
	int		len;
	int		plusp;

	plusp = 0;
	sptr = sel_arglist(pfs)->str;
	if (pfs->prec && pfs->precvalue == 0 && !ft_strcmp(sptr, "0"))
	{
		//ft_strdel(&s);
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
	if (*s == '-')
		plusp = 1;
	if (pfs->prec && pfs->precvalue > (len - plusp))
		s = precdigits(s, &len, plusp, pfs);
	if (pfs->flags[3] && !pfs->flags[4] && !plusp)
		s = flag_space(s, &len, pfs);
	if (pfs->flags[4] && !plusp)
		s = flag_plus(s, &len, pfs);
	if (pfs->fwidth && len < pfs->fwidthvalue)
		s = field_width_num(s, &len, pfs);
	store_write(pfs, s, &len);
	if (pfs->converted)
		ft_strdel(&s);
}
