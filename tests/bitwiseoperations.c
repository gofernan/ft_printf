/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwiseoperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:26:06 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/05 19:45:59 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
//#include <locale.h>
#include <unistd.h>
int main(void)
{
	unsigned int a;
	int b;
	int c;
	int calt;
	int d;
	int testhex;
	int binnb;
	char octnb;
	char buf[sizeof("256")];
	short forumex;

	//setlocale(LC_ALL, "en_US.UTF-8");
	a = 4294967295;
	a = a << 32;
	b = 0x80000001;
	c = 0x80000000;
	calt = 0x80000001;
	d = 0x40000000;
	testhex = 0x40000000;
	octnb = 0101;
	binnb = 0b1;
	forumex = 0xc280;
	//b = b << 1;
	printf("a:%u\n", a);
	printf("b:%d\n", b);
	printf("%lu\n", sizeof(unsigned int));
	printf("Size of 256:%lu\n", sizeof("256"));
	printf("Size of array:%lu\n", sizeof(buf));
	printf("test hex: %d\n", testhex);
	printf("MAX UNSIGNED INT: %u\n", UINT_MAX);
	printf("C value: shifted right 31 times:%d\n", c >> 2);
	printf("Calt value: %d\n", calt);
	printf("D shifted 1 to left:%d\n", d >> 1);
	printf("octnb:%c\n", octnb);
	printf("binnb:%d\n", binnb);
	printf("forumex: %d\n", forumex);
	printf("char 𐀀⇵\n");
	unsigned char e;
	e = 0xe1;
	write(1, &e, 1);
	e = 0x88;
	write(1, &e, 1);
	e = 0xb4;
	write(1, &e, 1);
	unsigned char unicode3bytes;
	unicode3bytes = 0xec; //1011 1010
	write(1, &unicode3bytes, 1);
	unicode3bytes = 0x8a;
	write(1, &unicode3bytes, 1);
	unicode3bytes = 0x80;
	write(1, &unicode3bytes, 1);
	//e = 0x0a;
	//write(1, &e, 1);
	return (0);
}
