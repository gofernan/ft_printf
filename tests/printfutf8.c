/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfutf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:51:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/05 20:24:46 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>
int main(void)
{
	setlocale(LC_ALL, "");
	printf("my string: %s\n", "슀my cool string");
	printf("ο Δικαιοπολις εν αγρω εστιν\n");
	printf("%ls", L"ο Δικαιοπολις εν αγρω εστιν\n");
	char str[] = "αγρω𐀀";
	printf("str:%s\n", str);
	printf("%lu %lu\n", sizeof(str), strlen(str));
	printf("size of wchar_t:%lu", sizeof(wchar_t));
	return (0);
}
