/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_xX.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:52:25 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 15:20:02 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(int num, int fd, char c)
{
	const char		*hex_digits;
	char			buffer[20];
	int				i;
	int				count;
	unsigned int	unsigned_num;

	unsigned_num = (unsigned int)num;
	i = 0;
	count = 0;
	if (unsigned_num == 0)
		return (ft_putchar_fdp('0', fd));
	if (c == 'x')
		hex_digits = "0123456789abcdef";
	else if (c == 'X')
		hex_digits = "0123456789ABCDEF";
	while (unsigned_num > 0)
	{
		buffer[i++] = hex_digits[unsigned_num % 16];
		unsigned_num /= 16;
	}
	while (i-- > 0)
		count += write(fd, &buffer[i], 1);
	return (count);
}
