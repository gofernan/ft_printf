/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 10:00:38 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/15 16:35:52 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

//void		check_list(

char		*argorder(va_list ap, fstr_t *ptrfstring)
{
	char		*s;
	t_args		largs;
	t_args		*ptrlargs;

	ptrlargs = &largs;

	if (ptrfstring->convesp == 's' && !(ptrfstring->lengthmdf[2]))
		check_list(ap, ptrfstring);
}
