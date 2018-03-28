/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 05:27:05 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/06 22:11:51 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict dst,
		const void *restrict src, int c, size_t n)
{
	size_t			i;
	unsigned char	*strd;
	unsigned char	*strs;
	unsigned char	d;

	i = 0;
	strd = (unsigned char *)dst;
	strs = (unsigned char *)src;
	d = (unsigned char)c;
	while (i < n)
	{
		strd[i] = strs[i];
		if (strs[i] == d)
			return (&dst[i + 1]);
		i++;
	}
	return (NULL);
}
