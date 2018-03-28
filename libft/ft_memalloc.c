/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 06:23:32 by gofernan          #+#    #+#             */
/*   Updated: 2017/11/23 06:39:29 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*s1;

	s1 = malloc(size);
	if (s1 == NULL)
		return (NULL);
	ft_memset(s1, 0, size);
	return (s1);
}
