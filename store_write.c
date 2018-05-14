/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:25:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 17:26:01 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		store_write(fstr_t *ptrfstring, const char *s, int *len)
{
	int	i;

	i = 0;
	if (((ptrfstring->buffi) + *len) < BUFF_SIZE)
	{
		ft_strncpynp(&ptrfstring->buff[ptrfstring->buffi], s, *len);
		ptrfstring->buffi += *len;
	}
	else if (*len <= BUFF_SIZE)
	{
		ptrfstring->counter += write(1, ptrfstring->buff, ptrfstring->buffi);
		//while (i < ptrfstring->buffi)
		//	ptrfstring->buff[i++] = '\0';
		ptrfstring->buffi = 0;
		ft_strncpynp(ptrfstring->buff, s, *len);
		ptrfstring->buffi = *len;
	}
	else
		ft_putstr("NO ENTRA");
}
