/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 19:58:36 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/03 20:45:28 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nlen(long nb)
{
	int counter;

	counter = 1;
	if (nb < 0)
		counter++;
	if (nb < 0)
	{
		while (nb <= -10)
		{
			counter++;
			nb /= 10;
		}
	}
	else
	{
		while (nb >= 10)
		{
			counter++;
			nb /= 10;
		}
	}
	return (counter);
}
