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
	//ft_printf("yo%2C%-12lc et %C titi %C tyty", 'u', 254, 256, 'a');
	//ft_printf("%2$s", "holla");
	//
	//ft_printf("1234");
	//printf("%-2$#d%+d% 03$d%4$d%2$d%d", 42, 10, 20, 30, 40);
	//ft_printf("%s", "hola");
	ft_printf("%1$s%2$s%s", "hola", "que tal", "estas");
	//printf("%1$s%4$s%3$s%s", "hola", "que", "tal", "estas");
	//printf("%200$s%s%1$s%6$s", "hola", "amigo", "mio", "como", "estas", "hoy");
	return (0);
}
