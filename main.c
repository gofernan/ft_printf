/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:28:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 19:53:36 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
int main(void)
{
	int		ret;

	//ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//ft_printf("%2$s", "holla");
	//
	//ft_printf("1234");
	//printf("%-2$#d%+d% 03$d%4$d%2$d%d", 42, 10, 20, 30, 40);
	//ft_printf("%s", "hola");
	//ft_printf("%1$s%7$s%s", "hola", "que tal", "estas", "tio");
	//ft_printf("%2$s%7$s%s", "hola", "que tal", "estas", "tio", "si", "no", "puede", "tal vez");
	//ft_printf("%1$ls", L"hola");
	//ft_printf("%lX", 0xff11ff11ff1);
	//printf("%7$d%1$d%2$%yyyy%d", 1, 2, 3, 4, 5, 6, 7);
	ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256);
	//printf("%lc", 256);
	//printf("%.1ls", s);
	//printf("%S", s);
	//printf("%1$s%4$s%s", "hola", "que tal", "estas", "tio", "si");
	//printf("%2$s%1$s%s", "hola", "que tal", "estas");
	//printf("%1$s%7$d%3$s%4$s", "hola", "que", "tal", "estas", NULL, L"prueba", 18);
	//printf("%200$s%s%1$s%6$s", "hola", "amigo", "mio", "como", "estas", "hoy");
	return (0);
}
