/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:24:11 by bglover           #+#    #+#             */
/*   Updated: 2019/09/19 17:19:45 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pars_l(const char *restrict form, int i, va_list ap)
{
	if (form[i + 1] == 'd')
	{
		flag_ld(va_arg(ap, long long));
		return (1);
	}
	else if (form[i + 2] == 'd' && form[i + 1] == 'l')
	{
		flag_ld(va_arg(ap, long long));
		return (2);
	}
	else if (form[1 + i] == 'l' && form[2 + i] == 'u')
	{
		flag_llu(va_arg(ap, unsigned long long));
		return (2);
	}
	else if (form[1 + i] == 'u')
	{
		flag_u(va_arg(ap, unsigned));
		return (1);
	}
	return (0);
}

void		ft_printf(const char *restrict form, ...)
{
	va_list ap;
	int		i;

	i = 0;
	va_start(ap, form);
	while (form[i])
		if (form[i] == '%')
		{
			i++;
			if (form[i] >= '0' && form[i] <= '9')
			{
				cheak_point(ft_atoi_finder(form, '%'));
				i = ft_nbrlen(ft_atoi_finder(form, '%')) + i + 1;
			}
			if (form[i] == '.')
				i++;
			if (form[i] == 'd' || form[i] == 'i')
				ft_putnbr(va_arg(ap, int));
			else if (form[i] == 'o')
				flag_base(va_arg(ap, int), 8);
			else if (form[i] == 'c')
				ft_putchar(va_arg(ap, int));
			else if (form[i] == 's')
				ft_putstr(va_arg(ap, char *));
			else if (form[i] == 'u')
				flag_u(va_arg(ap, unsigned));
			if (form[i] == 'l')
				i += pars_l(form, i, ap);
			else if (form[i] == '%')
				write(1, &form[i], 1);
			i++;
		}
		else
			write(1, &form[i++], 1);
}
