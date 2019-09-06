/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:50:28 by bglover           #+#    #+#             */
/*   Updated: 2019/04/09 15:16:56 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt_parts(const char *s, char c)
{
	int		cnt;
	int		in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s)
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int	ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		index;

	if (!s || !c)
		return (NULL);
	index = 0;
	nb_word = ft_cnt_parts((const char *)s, c);
	if (!(tab = (char **)malloc(sizeof(*tab) * (nb_word + 1))))
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		if (!(tab[index] = ft_strsub((const char *)s, 0, \
		ft_wlen((const char *)s, c))))
		{
			free(tab);
			return (NULL);
		}
		s = s + ft_wlen(s, c);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
