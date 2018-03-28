/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 23:05:46 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/28 21:04:10 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <locale.h>
#include <unistd.h>
#include "../libft/libft.h"
#define TESTMACROMOLA "sSpdDioOuUxXcC"
#define MACROMOLA_L strlen(TESTMACROMOLA)

int main(void)
{

	setlocale(LC_ALL, "en_US.UTF-8");

	char *str = "hello";
	char *str2 = "hello2";
	char a = 'a';
	short numerito = 9;
	char tosgn = 65;
	const char *fconv[15];
	int b;
	char *strrare;
	unsigned long rarechar;

	strrare = "米a";
	rarechar = '米';

	printf("rare char: %zu\n", sizeof(char));
	printf("El integer b es: %d", b);
	printf("first of all, TESTMACRO LEN: %lu\n", strlen(TESTMACROMOLA));
	printf("len TESTMACROMOLA: %lu", MACROMOLA_L);
	//printf("str:%s\n", str);
	//printf("str2:%s\n", str2);
	printf("µ\n");
	write(1, "hola\na\ntodo\nel\nmundo\n", 22);
	printf("hola como%destas\n", 899);
	printf("lotofflags %#0-+d\n", 899899);



	fconv[0] = "hello how how how";
	fconv[1] = "I'm fine and you?";
	strcpy((char *)fconv[2], "abcde");
	printf("size of int: %lu\n", sizeof(int));
	printf("Maximum size of int: %d\n", INT_MAX);
	//strcpy(fconv[0], "hello how are you");
	printf("MAX NL: %d\n", NL_ARGMAX);
	printf("MIN NL: %d\n", _POSIX_ARG_MAX);
	printf("asterisk width: %*.1d\n", 10, 10);
	printf("without asterisk but string: %*.*s\n", 10, 2, "hello my friend");
	printf("%%\n");
	printf("%c", 66);
	printf("%c\n", 0x23);
	printf("%hhd\n wooooola\n", a);
	setlocale(LC_NUMERIC, "");
	printf("signed flag: %11$d %1$d %3$d %10$d %9$d %8$d %7$d %6$d %5$d %4$d %2$d %12$d %13$d %14$d %15$d %30$d\n", 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150,
			10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 151);
	printf("%hd\n", 1);
	printf("% #-d%diez\n", 10, 20);
	printf("strlen strrare: %zu\n", ft_strlen(strrare));
	printf("size of strrare: %lu\n", sizeof(strrare));
	ft_putchar(rarechar);
	//printf("%12-+d", 6999) bad composed

	//printf("%1$s", fconv[0], fconv[1]);
	//printf("%s", fconv[2]);
	//printf("%O", 10);
	/*
	printf("% d\n",102030);
	printf("%-77d\n", 699);
	//printf("%10c", a);
	//printf("%-2hi", 1, 32700);
	printf("el numerito es %hi", numerito);
	printf("el numerito es %i", 9);
	printf("d converted to signed char %hhd", tosgn);
	printf("size of char is %lu", sizeof(char));
	printf("max of int %d", INT_MAX);
	*/
  	return (0);
}
