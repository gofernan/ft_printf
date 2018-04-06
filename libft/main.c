/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 15:53:25 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/06 16:03:15 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
size_t			ft_wcslen(const wchar_t *str);

int main(void)
{
	wchar_t *strw = L"my wide char stringݘබ1";

	printf("%zu\n", ft_wcslen(strw));
	printf("%zu\n", wcslen(strw));
	printf("%zu\n", sizeof(wchar_t));

	return (0);
}
