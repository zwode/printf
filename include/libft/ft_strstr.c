/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/28 21:43:01 by bglover           #+#    #+#             */
/*   Updated: 2019/04/28 21:43:04 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		while (haystack[i] == needle[j] || needle[j] == '\0')
		{
			if (needle[j] == '\0')
				return ((char *)haystack);
			i++;
			j++;
		}
		j = 0;
		i = 0;
		haystack++;
	}
	return (NULL);
}
