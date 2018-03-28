/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:50:41 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 16:52:44 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#define MISTR "марко"
//#include <unistd.h>

int 		main(void)
{
	int a;
	int b;
	//setlocale(LC_ALL, "ja_JP.UTF-8");
	//char *string;
	a = 0;
	b = 0;

	//string = (char *)malloc(sizeof(char) * ((strlen(MISTR) + 1)));
	//strcpy(string, MISTR);
	//string[ft_strlen(MISTR)] = '\0';
	a = printf("%.20$d\n", 10);
	b = printf("%30-jhl10+#ll&ola+.hd %10ñ+65d %C\n", 65, 65, 65);
	printf("PRUEBA con %h32hhd\n", 'A');
	printf("mi caracter chachi: 語ñツ\n");
	printf("1er numero %2$d, 2o numero: %d\n", 1, 2, 3);
	write(1, "WOLAñツ", 20);
	//write(1, string, strlen(string)); 
	printf("%d30-+. %d %C\n", 65, 65, 65);
	printf("%40-hello%d\n", 10);
	printf("%40-ello%d\n", 10);
	printf("%40ll-od%\n", 10);
	printf("%2$i %1$i %3$i %4$i %i", 10, 20, 30, 40, 50);
	printf("%hhd\n", 65);
	printf("%hᑪhd%d\n", 120, 240);
	return (0);
}
