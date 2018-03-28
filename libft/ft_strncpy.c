/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 22:08:33 by gofernan          #+#    #+#             */
/*   Updated: 2017/11/17 19:31:10 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;
	int a;

	i = 0;
	a = len;
	while ((i < a) && (src[i] != '\0'))
	{
		dst[i] = src[i];
		i++;
	}
	while (i < a)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
