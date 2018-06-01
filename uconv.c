/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:35:16 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:36:14 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*umdfs(va_list ap, t_args *tmpargsl)
{
	char *s;

	if (tmpargsl->convesp == 'U')
		s = ft_uimaxtoa(va_arg(ap, unsigned long));
	else if (tmpargsl->mdf == 7)
		s = ft_uimaxtoa(va_arg(ap, u_quad_t));
	else if (tmpargsl->mdf == 6)
		s = ft_uimaxtoa(va_arg(ap, size_t));
	else if (tmpargsl->mdf == 5)
		s = ft_uimaxtoa(va_arg(ap, ptrdiff_t));
	else if (tmpargsl->mdf == 4)
		s = ft_uimaxtoa(va_arg(ap, uintmax_t));
	else if (tmpargsl->mdf == 3)
		s = ft_uimaxtoa(va_arg(ap, unsigned long long));
	else if (tmpargsl->mdf == 2)
		s = ft_uimaxtoa(va_arg(ap, unsigned long));
	else if (tmpargsl->mdf == 1)
		s = ft_uimaxtoa((unsigned short)va_arg(ap, unsigned int));
	else if (tmpargsl->mdf == 0)
		s = ft_uimaxtoa((unsigned char)va_arg(ap, unsigned int));
	else
		s = ft_uimaxtoa(va_arg(ap, unsigned int));
	if (!s)
		exit(EXIT_FAILURE);
	return (s);
}

void		uconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	char	*sptr;
	int		len;

	sptr = sel_arglist(ptrfstring)->str;
	if (ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(sptr, "0"))
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
	ptrfstring->converted = 1;
	if (ptrfstring->precision && ptrfstring->precisionvalue > len)
		s = precisiondigits(s, &len, 0, ptrfstring);
	if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
		s = field_width_num(s, &len, ptrfstring);
	store_write(ptrfstring, s, &len);
	if (ptrfstring->converted)
		ft_strdel(&s);
}
