/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:29:06 by bglover           #+#    #+#             */
/*   Updated: 2019/05/04 17:09:24 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (len >= (len - 1) && haystack[i] != '\0')
	{
		while (len >= (len - 1) && (haystack[i] == needle[j] ||
		needle[j] == '\0'))
		{
			if (needle[j] == '\0' && len >= (len - i))
				return ((char *)haystack);
			i++;
			j++;
		}
		i = 0;
		j = 0;
		haystack++;
		len--;
	}
	return (NULL);
}
