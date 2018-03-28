/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 11:00:14 by gofernan          #+#    #+#             */
/*   Updated: 2018/03/21 12:33:32 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <float.h>

int			main(void)
{
	short ashort;
	char achar;

	ashort = 32768;
	achar = 128;
	printf("printing short %d\n", ashort);
	printf("printng char %d\n", achar);
	printf("sizeof(unsignedlong): %lu & sizeof(unsigned int): %lu\n", sizeof(unsigned long), sizeof(unsigned int));
	printf("sizeof(short): %lu & sizeof(unsigned short): %lu\n", sizeof(short), sizeof(unsigned short));
	printf("sizeof(unsigned short): %lu\n", sizeof(unsigned short));
	printf("sizeof(float): %lu\n", sizeof(float));
	printf("minimun float value: %E\n", FLT_MIN);
	printf("minimun float value: %E\n", FLT_MAX);
	return (0);
}
