/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:18:36 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/06 15:22:42 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	char str[] = "hello how are youԸ";
	char str2[] = "hello how are youi";
	wchar_t *strw = L"This is a wide char stringሴ";
	wchar_t widechar = L'a';

	printf("len: %zu\n", ft_strlen(str));
	printf("len: %zu\n", ft_strlen(str2));
	printf("wide str %ls\n", strw);
	printf("wide char:%c\n", widechar);
	printf("wide str len: %zu\n", ft_strlen(strw));
	printf("%'s", str);

	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	write(1, str2, ft_strlen(str2));
	write(1, "\n", 1);
	return (0);
}
