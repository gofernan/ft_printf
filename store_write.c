/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_write.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:25:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/10/03 01:55:15 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		store_write(t_fstr *pfs, const char *s, int *len)
{
	int	i;

	if (((pfs->buffi) + *len) < pfs->buffsize)
	{
		ft_strncpynp(&pfs->buff[pfs->buffi], s, *len);
		pfs->buffi += *len;
	}
	else if (*len <= pfs->buffsize)
	{
		pfs->counter += write(1, pfs->buff, pfs->buffi);
		ft_strncpynp(pfs->buff, s, *len);
		pfs->buffi = *len;
	}
	else
	{
		i = 1000;
		pfs->counter += write(1, pfs->buff, pfs->buffi);
		//ft_strdel(&pfs->buff);
		free(pfs->buff);
		pfs->buff = NULL;
		while (*len <= pfs->buffsize)
			pfs->buffsize += i;
		if (!(pfs->buff = (char *)malloc(sizeof(char) * (pfs->buffsize + 1))))
			exit(EXIT_FAILURE);
		ft_strncpynp(pfs->buff, s, *len);
		pfs->buffi = *len;
	}
}
