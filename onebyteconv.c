/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1byteconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 15:20:35 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/30 16:42:19 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

unsigned char *onebyteconv(wchar_t * wstr)
{
	int i;
	unsigned char *casted1byte;
	int counter;
	int len;

	len = ft_wcslen(wstr);

	i = 0;

	casted1byte = ft_memalloc(sizeof(unsigned char) * (len + 1));
	ft_memset(casted1byte, 0, (sizeof(unsigned char) * (len + 1)));
	while (wstr[i])
	{
		casted1byte[i] = (unsigned char)wstr[i];
		i++;
	}
	return (casted1byte);
}
