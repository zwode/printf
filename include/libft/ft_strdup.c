/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 23:07:01 by bglover           #+#    #+#             */
/*   Updated: 2019/04/27 23:29:23 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*a;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	a = (char *)malloc(sizeof(char) * i + 1);
	if (!a)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		a[i] = s1[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
