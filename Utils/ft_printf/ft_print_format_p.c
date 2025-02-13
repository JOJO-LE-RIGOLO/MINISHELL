/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:49:47 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 15:16:10 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr, int fd)
{
	const char		*hex_digits;
	unsigned long	num;
	char			buffer[20];
	int				i;
	int				count;

	num = (unsigned long)ptr;
	if (num == 0)
		return (ft_putstr_fdp("(nil)", fd));
	hex_digits = "0123456789abcdef";
	i = 0;
	count = 0;
	while (num > 0)
	{
		buffer[i++] = hex_digits[num % 16];
		num /= 16;
	}
	count += ft_putstr_fdp("0x", fd);
	while (i-- > 0)
		count += write(fd, &buffer[i], 1);
	return (count);
}
