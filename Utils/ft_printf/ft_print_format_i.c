/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_i.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:48:38 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 15:13:33 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint_fd(int n, int fd)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		return (ft_putstr_fdp("-2147483648", fd));
	}
	if (n < 0)
	{
		count += ft_putchar_fdp('-', fd);
		n = -n;
	}
	if (n > 9)
		count += ft_putint_fd(n / 10, fd);
	count += ft_putchar_fdp((n % 10) + '0', fd);
	return (count);
}
