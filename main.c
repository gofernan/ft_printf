/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 12:28:51 by gofernan          #+#    #+#             */
/*   Updated: 2018/05/14 19:53:36 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <limits.h>
int main(void)
{
//	ft_printf("%2$s%1$s%5$s%3$s%4$s%2$s", "hola", "como", "estas", "tio", "mio");
	ft_printf("%2$s", "holla");
	//
	return (0);
}
