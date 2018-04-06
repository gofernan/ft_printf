/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writeexample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:18:54 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/06 19:36:48 by gofernan         ###   ########.fr       */
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
	//int happy[3];  /* U+263A */
	//char happy2[] = { 0x26, 0x3a };
//	char alpha[2] = {0xCE, 0xB1};
	wchar_t alpha = 0x3B1L;
	int check[3] = {226, 156, 147};
	wchar_t *strnormal = L"Hello";
	char *tmp;

	write(1, "\n", 1);
	write(1, &alpha, 4);

	tmp = (char*)(&alpha);

	write(1, "\n", 1);
	write(1, tmp, strlen(tmp));
	//happy[0] = 0xe2;
	//happy[1] = 0x98;
	//happy[2] = 0xba;
	
	//write(1, happy, 3);
	//write(1, &happy[0], 1);
	//write(1, &happy[1], 1);
	//write(1, &happy[2], 1);
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
//	printf("%S\n", strnormal);
}
