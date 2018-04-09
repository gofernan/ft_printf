/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeexample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:18:54 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/09 12:34:41 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>

size_t			ft_wcslen(const wchar_t *s);
int main()
{
	setlocale(LC_ALL, "");
	char happy2[3];  /* U+263A */
	//char happy2[] = { 0x26, 0x3a };
	int alphas2[2] = {0xCE, 0xB1};
	//wchar_t alpha = 0x3B1L;
	//wchar_t alpha = 0xceb1;
	wchar_t *alphas = L"α";
	//wchar_t alphas2[] = { 0xce, 0xb1}
	int check[3] = {226, 156, 147};
	wchar_t *strnormal = L"H";
	wchar_t strnormalhex = 0xC389;
	wchar_t strnormalb[1];
	//wchar_t *happy = L"☺";
	char *tmp;

	//write(1, &alpha, 4);
	
	write(1, strnormal, 4);
	write(1, &strnormalhex, 4);
	//strnormalb[0] = 0b01001000100000001000000010000000;
	strnormalb[0] = 0b00000010;
	write(1, "\n", 1);
	write(1, strnormalb, 4);
	//write(1, &strnormal[0], 4);
	//write(1, &strnormal[1], 4);
	//write(1, &strnormal[2], 4);
	//write(1, &strnormal[3], 4);
	//write(1, &strnormal[4], 4);
	//write(1, strnormal, 1);
	//happy2[0] = 0xe2;
	//happy2[1] = 0x98;
	//happy2[2] = 0xba;
	
	//write(1, happy, 3);
	//write(1, &happy2[0], 1);
	//write(1, &happy2[1], 1);
	//write(1, &happy2[2], 1);
	//
	//write(1, &alphas2[0], 1);
	//write(1, &alphas2[1], 1);

	printf("%S\n", alphas);
	//printf("%S\n", happy);
	//write(1, happy2, 2);
//	write(1, &alpha[0], 1);
//	write(1, &alpha[1], 1);
//	write(1, &check[0], 1);
//	write(1, &check[1], 1);
//	write(1, &check[2], 1);
//	write(1, "\n", 1);
	//printf("swclen * sizeof(strw):%zu\n", ft_wcslen(strnormal) * sizeof(wchar_t));
//	write(1,"\n",1);
//	write(1, alpha, 2);
//	write(1,"\n",1);
	//printf("%S\n", strnormal);
}
