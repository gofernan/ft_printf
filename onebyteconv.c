/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1byteconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:20:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/30 18:42:05 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char *onebyteconv(wchar_t * wstr, fstr_t *ptrfstring)
{
	int i;
	char *casted1byte;
	int counter;
	int len;

	i = -1;
	while (wstr[++i])
	{
		if (wstr[i] > 0xff)
		{
			if (ptrfstring->precision && ptrfstring->precisionvalue <= i )
				break;
			else
				return (NULL);
		}
	}
	len = ft_wcslen(wstr);
	if (!(casted1byte = ft_strnew(len)))
		return (NULL);
	i = -1;
	while (wstr[++i])
		casted1byte[i] = (char)wstr[i];
	return (casted1byte);
}
