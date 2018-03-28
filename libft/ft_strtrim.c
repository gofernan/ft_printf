/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:55:10 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/04 22:15:22 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_start(char const *sr, int a)
{
	while ((sr[a] == ' ' || sr[a] == '\n' || sr[a] == '\t') && sr[a] != '\0')
		a++;
	if (sr[a] == '\0')
		return (0);
	return (a);
}

static int		ft_last(char const *srr, int b)
{
	while ((srr[b] == ' ' || srr[b] == '\n' || srr[b] == '\t') && b >= 0)
		b--;
	if (b == 0)
		return (0);
	return (b);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		start;
	int		last;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (s[i] == '\0')
		return ((char *)s);
	while (s[i] != '\0')
	{
		if (i == 0)
			start = ft_start(s, i);
		if (s[i + 1] == '\0')
			last = ft_last(s, i);
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (last - start + 2))))
		return (NULL);
	i = 0;
	while (start <= last)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
