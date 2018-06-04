/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_defaultv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 10:50:40 by gofernan          #+#    #+#             */
/*   Updated: 2018/06/04 11:01:42 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void		fill_defaultv(t_args *tmpargsl, int *i)
{
	tmpargsl->value = *i;
	tmpargsl->conv = 's';
	tmpargsl->mdf = -1;
	tmpargsl->str = NULL;
	tmpargsl->next = NULL;
}
