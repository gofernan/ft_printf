/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 22:35:15 by gofernan          #+#    #+#             */
/*   Updated: 2017/11/23 04:26:42 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *pos;

	pos = NULL;
	while (*s)
	{
		if (*s == (char)c)
			pos = (char *)s;
		s++;
	}
	if (((*s) == '\0') && (c == '\0'))
		return ((char *)s);
	if (pos != NULL)
		return (pos);
	return (NULL);
}
