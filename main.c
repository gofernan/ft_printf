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
	char a = 'a';

	printf("res: %d" , ft_printf("%4C", (wchar_t)0));
	printf("reso: %d", printf("%4C", (wchar_t)0));
	//int i = printf("\nHola\n%c,pizaww? %C\n", 20, -65);
	return (0);
}
