/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sconv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:11:15 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/03 13:21:31 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
//flag # no effect
//- override 0
void	sconv(va_list ap)
{
	char *s;

	s = va_arg(ap, char *);

	write(1, s, (ft_strlen(s) + 1));
}
