/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmodifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:44:08 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 13:50:48 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	int a;
	int b;

	a = 32769;
	b = 128;

	printf("%h-0hhd\n", a);
	printf("%hh-0hd\n", a);
	printf("%hhd\n", a);
	printf("%hd\n", b);
	printf("%hhhhd\n", b);
	printf("%hhhd\n", b);
	return (0);
}
