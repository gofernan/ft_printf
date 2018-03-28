/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gofernan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 00:07:40 by gofernan          #+#    #+#             */
/*   Updated: 2017/12/07 01:02:18 by gofernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countwords(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

static char		*ft_word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = NULL;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (!(word = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void		ft_assign(char const *s, char c, char **strconv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			strconv[j] = ft_word(&s[i], c);
			j++;
		}
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	strconv[j] = 0;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strconv;

	if (s == NULL)
		return (NULL);
	if (!(strconv = (char **)malloc(sizeof(char *) *
					(ft_countwords(s, c) + 1))))
		return (NULL);
	ft_assign(s, c, strconv);
	return (strconv);
}
