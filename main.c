/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:28:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/06 13:50:38 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
int main(void)
{
	char *str1 = "hello";
	char *str2 = "how";
	char *str3 = "are";
	char *str4 = "you";
	char *str5 = "bye";
	char **strings;

	//ft_printf("leading string :%#hhh.745s, trailing string% 'sx %1$tzjl Xbla\n", str1, str2, str3, str4, str5);
	//printf("counter: %d\n", ft_printf("Ѫઆaᴻ"));
	//ft_printf("%d", ft_printf("Ѫઆaᴻ"));
	ft_printf("%0 +19s", "hello how are you?Ѫ");
	printf("%0 +19s", "hello how are you?Ѫ");
	//printf("num char: %d", printf("%s", "Ѫa"));
	printf("\n");
	//printf("%030s", "hello how are you?Ѫ");
	printf("%040s", "      holaholita");
	//setlocale(P_ALL, "en_US.UTF-8");
	/*pep check
	int i = printf("\nHola\n%c,pizaww? %C\n", 20, -65);
	ft_putnbr(i);
	*/
	return (0);
}
