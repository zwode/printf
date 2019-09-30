/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:31:06 by zwode             #+#    #+#             */
/*   Updated: 2019/09/29 17:08:30 by zwode            ###   ########.fr       */
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

int		ft_atoi_finder(const char *str, int sym)
{
	int		res;
	int		i;

	i = sym;
	res = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res);
}

void	cheak_point(const char *form, int i)
{
	int num;
	int b;

	b = 0;
	num = ft_atoi_finder(form, i);
	while (num >= b)
	{
		ft_putchar(' ');
		b++;
	}
}

void	cheak_zero(const char *form, int i, int counter)
{
	int num;

	num = ft_atoi_finder(form, i) - counter;
	while (num >= 0 && ft_putchar('0'))
		num--;
}

int		cheaker_point(int num, const char *form, int i, va_list ap)
{
	int counter;

	counter = 0;
	if (num == 0)
		cheak_point(form, i);
	else
		cheak_zero(form, i, counter);
	return (ft_nbrlen(ft_atoi_finder(form, i)));
}
