/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:28:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/23 21:11:34 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
int main(void)
{
	//wchar_t strw[4];
	//char a = 'a';
	//int i;

	//strw[0] = 0xd800;
	//strw[1] = L'u';
	//strw[2] = L'a';
	//strw[3] = '\0';

	//printf("res: %d" , ft_printf("%4C", (wchar_t)0));
	//printf("reso: %d", printf("%4C", (wchar_t)0));
	//i = printf("\nHola\n%c,pizaww?%S\n", 'c', strw);
	//printf("%yyyyyyyyyyyyyyyyy", 10);
	//printf("%d", ft_printf("%yyd%C", 10, -60));
	//printf("%d", printf("%yyd%C", 10, -60));
	//printf("%d", printf("%#010%"));
	//ft_printf("%#0-10%");
	//ft_printf("%ld", LONG_MIN);
	//ft_printf("%ld", LONG_MIN);
	ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	return (0);
}
