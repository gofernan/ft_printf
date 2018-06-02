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

void		store_write(t_fstr *pfs, const char *s, int *len)
{
	int	i;

	i = 0;
	if (((pfs->buffi) + *len) < BUFF_SIZE)
	{
		ft_strncpynp(&pfs->buff[pfs->buffi], s, *len);
		pfs->buffi += *len;
	}
	else if (*len <= BUFF_SIZE)
	{
		pfs->counter += write(1, pfs->buff, pfs->buffi);
		//while (i < pfs->buffi)
		//	pfs->buff[i++] = '\0';
		ft_strncpynp(pfs->buff, s, *len);
		pfs->buffi = *len;
	}
	else
		ft_putstr("NO ENTRA");
}
