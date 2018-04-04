/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwiseoperations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 19:26:06 by gofernan          #+#    #+#             */
/*   Updated: 2018/04/04 20:32:22 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
int main(void)
{
	unsigned int a;
	int b;
	int testhex;

	a = 4294967295;
	a = a << 32;
	b = 0x80000001;
	testhex = 0x40000000;
	//b = b << 1;
	printf("a:%u\n", a);
	printf("b:%d\n", b);
	printf("%lu\n", sizeof(unsigned int));
	printf("test hex: %d\n", testhex);
	printf("MAX UNSIGNED INT: %u\n", UINT_MAX);
	return (0);
}
