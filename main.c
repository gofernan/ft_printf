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
int main(void)
{
	int a = -71;
	//unsigned int b = 2147483648;
	/*char *str1 = "hello";
	char *str2 = "how";
	char *str3 = "are";
	char *str4 = "you";
	char *str5 = "bye";
	char **strings;
	*/
	//setlocale(LC_ALL, "");
	//ft_printf("leading string :%#hhh.745s, trailing string% 'sx %1$tzjl Xbla\n", str1, str2, str3, str4, str5);
	//printf("counter: %d\n", ft_printf("Ѫઆaᴻ"));
	//ft_printf("%d", ft_printf("Ѫઆaᴻ"));
	//printf("counter: %d\n", ft_printf("%-52.2s", "I know what you are doing."));
	//printf("counter final: %d\n", ptrfstring->counter);
	
	//printf("counter %d\n", printf("!%-2.42ls!", L"┬─┬ ノ( ゜-゜ノ)"));
	//printf("counter %d\n", ft_printf("!%-2.42ls!", L"┬─┬ ノ( ゜-゜ノ)"));
	
	//printf("!%39.5ls!", NULL);
	//ft_printf("!%39.5ls!", NULL);
	
	//printf("%ld\n", a);
	//ft_printf("%ld\n", a);
	ft_printf("%08d\n", a);
	printf("%08d\n", a);

	//printf("%0 -21.22s", "hello how are you?Ѫ");
	//printf("num char: %d", printf("%s", "Ѫa"));
	//printf("\n");
	//printf("%030s", "hello how are you?Ѫ");
	//printf("%040.12s", "      holaholita");
	//setlocale(P_ALL, "en_US.UTF-8");
	/*pep check
	int i = printf("\nHola\n%c,pizaww? %C\n", 20, -65);
	ft_putnbr(i);
	*/
	return (0);
}
