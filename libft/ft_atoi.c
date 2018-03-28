/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:28:11 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/04 23:37:03 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		num;
	int		neg;

	num = 0;
	neg = 0;
	i = 0;
	while ((str[i] == '\n' || str[i] == '\t' || str[i] == '\v' ||
				str[i] == '\r' || str[i] == '\f' || str[i] == ' '))
		i++;
	if (str[i] == '-')
		neg = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		num *= 10;
		num += (int)str[i] - '0';
		i++;
	}
	if (neg == 1)
		return (num = -num);
	else
		return (num);
}
