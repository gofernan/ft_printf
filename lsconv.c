/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsconv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:01:26 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:18:03 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*check_locale_lsconv(va_list ap, t_args *tmpargsl)
{
	wchar_t		*wstr;
	char		*strconv;

	if (!(wstr = va_arg(ap, wchar_t *)))
	{
		if (!(strconv = (char *)malloc(sizeof(char) * 8)))
			exit(EXIT_FAILURE);
		ft_strcpy(strconv, "(null)");
		//ptrfstring->converted = 1;
	}
	else
	{
		if (MB_CUR_MAX == 4)
			strconv = utf8conv((unsigned int *)wstr);
		else
			strconv = onebyteconv(wstr, tmpargsl);
	}
	return (strconv);
}

void	lsconv(va_list ap, fstr_t *ptrfstring)
{
	char		*strconv;
	char		*strnull;
	int			len;

	if (ptrfstring->precheck)
		store_arglist(ptrfstring);
	else
	{
		strconv = sel_arglist(ptrfstring);
		ptrfstring->converted = 1;
		if (strconv)
		{
			len = ft_strlen(strconv);
			if (ptrfstring->precision && len > ptrfstring->precisionvalue)
			{
				if (MB_CUR_MAX == 4)
					strconv = precisionfw(strconv, &len, ptrfstring);
				else
					strconv = precisionf(strconv, &len, ptrfstring);
			}
			if (ptrfstring->fwidth && len < ptrfstring->fwidthvalue)
				strconv = field_width(strconv, &len, ptrfstring);
			store_write(ptrfstring, strconv, &len);
		}
		else
			ptrfstring->counter = -1;
		if (ptrfstring->converted)
			ft_strdel(&strconv);
	}
}
