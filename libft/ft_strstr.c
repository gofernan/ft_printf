/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:31:58 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/07 01:07:42 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strstr_solver(const char *hay, const char *n, int a, int b)
{
	int		k;
	char	*star;

	star = NULL;
	while (hay[a] != '\0')
	{
		b = 0;
		if (n[b] == hay[a])
		{
			star = (char *)&hay[a];
			k = a;
			while ((n[b] == hay[k]) && (n[b] != '\0'))
			{
				b++;
				k++;
			}
			if (n[b] == '\0')
				return (star);
		}
		a++;
	}
	return (NULL);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	return (ft_strstr_solver(haystack, needle, i, j));
}
