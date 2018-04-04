/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 11:18:36 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/04 12:26:52 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>

int main(void)
{
	char str[] = "hello how are youԸ";
	char str2[] = "hello how are youi";


	printf("len: %zu\n", ft_strlen(str));
	printf("len: %zu\n", ft_strlen(str2));
	printf("%'s", str);

	write(1, str, ft_strlen(str));
	write(1, str2, ft_strlen(str2));

	return (0);
}
