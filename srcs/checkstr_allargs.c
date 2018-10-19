/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkstr_allargs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 22:02:03 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:02:40 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		checkstr_allargs(const char *str, t_fstr *pfs)
{
	int		i;
	int		go;

	i = 0;
	go = 0;
	pfs->precheck = 1;
	while (str[i] != '\0')
	{
		if (go == 0)
		{
			if (str[i] == '%')
				go = 1;
		}
		else
		{
			go = checkstr_inside(str, pfs, &i);
		}
		i++;
	}
}
