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
	//printf("%*30.8*s%2$d", 40, 20, "hellow how are u?");
	//ft_printf("%s", "hola como estas");
	//ft_printf("%*2$s", 40, "hola");
	//printf("%255$s%s", "hola", "que tal");
	//ft_printf("%*.*10s", 40, 2, "hola");
	//printf("%*.*10s", 40, 2, "hola");
	//ft_printf("{%05.*d}", -15, 42);
	//printf("%e", 0.0);
	printf("%.15f", 9.1234567890123456);
	

	return (0);
}
