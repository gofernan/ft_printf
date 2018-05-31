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
	//setlocale(LC_ALL, "");
	double mynum = 2.1234344312;
	double mynum2 = 9.123456789912345678;
	double mynum3 = 9.123;
	double mynum4 = 37.975;
	int		mynumi1;
	int		mynumi2;
	wchar_t *strw;

	//strw = L"Ɋb";
	//mynumi1 = (int)mynum3;
	//mynumi2 = (mynum3 - mynumi1) * 1000000;
	//printf("%.6f\n", mynum3);
	//printf("%d\n", mynumi2);
	//printf("%.14f\n", mynum2);
	//printf("%.0f\n", mynum);
	//printf("%+10.2f\n", mynum4);
	//ft_printf("%d%f\n", 40, mynum);
	//printf("%d%.70f\n", 40, mynum);
	//ft_printf("%s", "0\n?v??");
	//ft_printf("%d %d\n", 6);
	//ft_printf("%*.*d", 25, 20, 10);
	printf("%0$.*d%d", 10, 8, 40);
	//ft_printf("%245$d%1$d%*2$.*1$34d%6$d", 10, 8, 40, 56, 83, 90);
	//ft_printf("%3$1-.*d", 10, 2, 5, 6);
	//ft_printf("%*1$.*2$d\n%d%4$*.d", 20, 10, 30, 40, 50);

	//ft_printf("%*6$.*d\n", 10, 14, 5, 7, 8);
	//ft_printf("%*.*d", 0, 3, 0);	
	//ft_printf("%*3d", 0, 0);
	return (0);
}
