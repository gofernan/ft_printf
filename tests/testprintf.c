/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 16:38:39 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/23 17:47:21 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	wchar_t *wstr = L"ȌHow you going";
	
	printf("%.4ls", wstr);
	//printf("%d\n", printf("%.4s", "This is a simple string\n"));
	//printf("%d\n", printf("hello how are you?Ѫ\n"));
	return (0);
}
