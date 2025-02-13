/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:49:29 by jojo              #+#    #+#             */
/*   Updated: 2024/11/18 15:12:58 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_format(char c, va_list args)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fdp(va_arg(args, int), 1);
	else if (c == 's')
		len += ft_putstr_fdp(va_arg(args, char *), 1);
	else if (c == 'i' || c == 'd')
		len += ft_putint_fd(va_arg(args, int), 1);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, void *), 1);
	else if (c == 'u')
		len += ft_putunsigned_fd(va_arg(args, unsigned int), 1);
	else if (c == 'x' || c == 'X')
		len += ft_putnbr_hex(va_arg(args, int), 1, c);
	else if (c == '%')
		len += ft_putchar_fdp(c, 1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_print_format(format[i + 1], args);
			i++;
		}
		else
		{
			ft_putchar_fdp(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
