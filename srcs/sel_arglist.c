/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sel_arglist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 21:47:09 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/02 22:09:13 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_args		*sel_arglist(t_fstr *pfs)
{
	t_args	*tmpargsl;

	tmpargsl = pfs->ptrlargs;
	while (tmpargsl->value != pfs->argov)
		tmpargsl = tmpargsl->next;
	return (tmpargsl);
}
