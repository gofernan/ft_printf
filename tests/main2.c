/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:50:41 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/02 17:40:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#define MISTR "марко"
//#include <unistd.h>

int 		main(void)
{
	int a;
	int b;
	char c;
	char chhex = 0x59;
	char *str1 = "\x59\x5a\x5b\x5c\x5d\x5e";
	//wchar_t wch = L'ڇ';
	wchar_t *mysun;
	setlocale(LC_ALL, "en_US.UTF-8");
	//char *string;
	a = 0;
	b = 0;
	c = 128;

	//string = (char *)malloc(sizeof(char) * ((strlen(MISTR) + 1)));
	//strcpy(string, MISTR);
	//string[ft_strlen(MISTR)] = '\0';
	mysun = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	mysun[0] = 0xd7;
	mysun[1] = 0xa6;
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
	printf("%2$i %1$i %3$i %4$i %i\n", 10, 20, 30, 40, 50);
	printf("%hhd\n", 65);
	printf("%hᑪhd%d\n", 120, 240);
	//printf("printf  lalala wchar_t: %C\n", wch);
	printf("printf wchar_t: %C\n", 110);
	printf("char hex: %c\n", chhex);
	printf("str1: %s\n", str1);
	printf("num en char %d\n", c);
	printf("sizeof(wchar_t): %lu\n", sizeof(wchar_t));
	if (printf("my sun: %ls\n", mysun) < 0)
		perror("printf");
	return (0);
}
