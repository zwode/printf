/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zwode <zwode@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 18:24:11 by bglover           #+#    #+#             */
/*   Updated: 2019/09/30 14:02:12 by zwode            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		pars_l(const char *restrict form, int i, va_list ap)
{
	int j;

	if (form[i++] == 'd')
		flag_ld(va_arg(ap, long long));
	else if (form[i--] == 'd' && form[i++] == 'l')
		flag_ld(va_arg(ap, long long));
	else if (form[i--] == 'u' && form[i++] == 'l')
		flag_llu(va_arg(ap, unsigned long long));
	else if (form[i++] == 'u')
		flag_u(va_arg(ap, unsigned));
	j -= i;
	return (ft_nbrlen(i));
}

int		num_purs(const char *form, int i, va_list ap)
{
	int counter;

	counter = 0;
	if (form[i] == 'd' || form[i] == 'i')
		counter += ft_putnbr(va_arg(ap, int));
	else if (form[i] == 'o')
		flag_base(va_arg(ap, int), 8);
	else if (form[i] == 'u')
		counter += flag_u(va_arg(ap, unsigned));
	if (form[i] == 'l')
		i += pars_l(form, i, ap);
	else if (form[i] == 'f')
		counter += ft_print_float(va_arg(ap, double), 0);
	return (counter);
}

int		sym_purs(const char *form, int i, va_list ap)
{
	int counter;

	counter = 0;
	if (form[i] == 'c')
		counter += ft_putchar(va_arg(ap, int));
	else if (form[i] == 's')
		counter += ft_putstr(va_arg(ap, char *));
	return (counter);
}

int		pointer_pars(const char *form, int i, va_list ap)
{
	if ((form[i] >= '0' && form[i] <= '9') || form[i] == '*')
		i += cheaker_point(0, form, i, ap);
	if (form[i] >= '0' && form[i] <= '9')
		i += cheaker_point(1, form, i, ap);
	return (i);
}

int		operator_pars(const char *form, int i, va_list ap)
{
	while (form[i])
	{
		if ((form[i] >= '0' && form[i] <= '9') || form[i] == '*')
			i += cheaker_point(0, form, i, ap) + 1;
		if (form[i] == '.')
			i++;
		if (form[i] >= '0' && form[i] <= '9')
			i += cheaker_point(1, form, i, ap);
		if (form[i] == '%')
			write(1, &form[i], 1);
	}
	return (i);
}

int		parsing(const char *restrict form, va_list ap)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (form[i++])
		if (form[i] == '%')
		{
			counter += operator_pars(form, i, ap);
		}
	return (i);
}

int		ft_printf(const char *restrict form, ...)
{
	va_list ap;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(ap, form);
	while (form[i])
		if (form[i] == '%')
		{
			i++;
			if ((form[i] >= '0' && form[i] <= '9') || form[i] == '*')
				i += cheaker_point(0, form, i, ap) + 1;
			if (form[i] == '.')
				i++;
			if (form[i] >= '0' && form[i] <= '9')
				i += cheaker_point(1, form, i, ap);
			else if (form[i] == '%')
				counter += write(1, &form[i], 1);
			i++;
		}
		else
			write(1, &form[i++], 1);
	return (counter);
}
