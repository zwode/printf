/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:32:32 by bglover           #+#    #+#             */
/*   Updated: 2019/04/20 20:06:20 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*a;
	const unsigned char		*b;
	size_t					i;

	a = (unsigned char *)dst;
	b = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		a[i] = b[i];
		if (b[i] == (unsigned char)c)
		{
			return (a + i + 1);
		}
		i++;
	}
	return (NULL);
}
