/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bglover <bglover@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:35:03 by bglover           #+#    #+#             */
/*   Updated: 2019/06/21 18:20:38 by bglover          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		if (!(str = (char*)malloc(sizeof(str) * ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcat(str, s2);
		return (str);
	}
	if (!s2)
	{
		if (!(str = (char*)malloc(sizeof(str) * ft_strlen(s1) + 1)))
			return (NULL);
		ft_strcat(str, s1);
		return (str);
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(str) * len + 1)))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, s2);
	return (str);
}
