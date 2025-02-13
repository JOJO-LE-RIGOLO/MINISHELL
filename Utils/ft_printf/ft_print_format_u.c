/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:51:19 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/18 15:18:49 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned_fd(unsigned int num, int fd)
{
	char	buffer[20];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (num == 0)
		return (ft_putchar_fdp('0', fd));
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i-- > 0)
		count += write(fd, &buffer[i], 1);
	return (count);
}
