/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:31:06 by zwode             #+#    #+#             */
/*   Updated: 2019/09/20 19:20:59 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		flag_llu(unsigned long long num)
{
	unsigned long long i[2];

	i[0] = 0;
	if (num == (1844674407370955161.5 * 10))
	{
		ft_putstr("18446744073709551615");
		return (1);
	}
	while (num > 0)
	{
		i[0] = num % 10 + (i[0] * 10);
		num /= 10;
	}
	i[1] = ft_nbrlen(i[0]);
	while (i[1] > 0)
	{
		ft_putchar((i[0] % 10) + '0');
		i[0] /= 10;
		i[1]--;
	}
	return (0);
}

int		ft_atoi_finder(const char *str, char sym)
{
	int i;
	int num;

	num = 0;
	i = 0;
	while (str[i] != sym && str[i] != '\0')
		i++;
	if (str[i] == sym)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	num /= 10;
	return (num);
}

void	cheak_point(int num)
{
	int i;

	i = 0;
	if (num < 0)
		num *= -1;
	while (num >= i)
	{
		ft_putchar('	');
		i++;
	}
}