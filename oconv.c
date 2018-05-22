/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 21:39:57 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/07 21:40:10 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char		*omdfs(va_list ap, t_args *tmpargsl)
{
	char *s;

	if (tmpargsl->convesp == 'O')
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long), 8, 0);
	else if (tmpargsl->mdf == 7)
		s = ft_uimaxtoa_base(va_arg(ap, u_quad_t), 8, 0);
	else if (tmpargsl->mdf == 6)
		s = ft_uimaxtoa_base(va_arg(ap, size_t), 8, 0);
	else if (tmpargsl->mdf == 5)
		s = ft_uimaxtoa_base(va_arg(ap, ptrdiff_t), 8, 0);
	else if (tmpargsl->mdf == 4)
		s = ft_uimaxtoa_base(va_arg(ap, uintmax_t), 8, 0);
	else if (tmpargsl->mdf == 3)
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long long), 8, 0);
	else if (tmpargsl->mdf == 2)
		s = ft_uimaxtoa_base(va_arg(ap, unsigned long), 8, 0);
	else if (tmpargsl->mdf == 1)
		s = ft_uimaxtoa_base((unsigned short)va_arg(ap, unsigned int), 8, 0);
	else if (tmpargsl->mdf == 0)
		s = ft_uimaxtoa_base((unsigned char)va_arg(ap, unsigned int), 8, 0);
	else
		s = ft_uimaxtoa_base(va_arg(ap, unsigned int), 8, 0);
	if (!s)
		exit(EXIT_FAILURE);
	return (s);
}

void		oconv(va_list ap, fstr_t *ptrfstring)
{
	char	*s;
	int		len;

	s = NULL;
	/*if (ptrfstring->precheck)
	{
		if (ptrfstring->argorder)
			store_arglist(ap, ptrfstring);
	}
	else
	*/
	if (ptrfstring->precheck)
		store_arglist(ptrfstring);
	else
	{
		//s = omdfs(ap, ptrfstring, s);
		s = sel_arglist(ptrfstring);
		ptrfstring->converted = 1; // needed???
		len = ft_strlen(s);
		if ((ptrfstring->precision && ptrfstring->precisionvalue == 0 && !ft_strcmp(s, "0"))
			|| (!ft_strcmp(s, "0") && ptrfstring->flags[0]))
		{
			*s = '\0';
			len = 0;
		}
		if (ptrfstring->flags[0])
			s = flag_sharp(s, &len, ptrfstring);
		if (ptrfstring->precision && ptrfstring->precisionvalue > len)
			s = precisiondigits(s, &len, 0, ptrfstring);
		if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
			s = field_width_num(s, &len, ptrfstring);
		store_write(ptrfstring, s, &len);
		if (ptrfstring->converted)
			ft_strdel(&s);
	}
}
