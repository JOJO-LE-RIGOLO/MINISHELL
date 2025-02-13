/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:52:53 by jojo              #+#    #+#             */
/*   Updated: 2024/11/18 15:21:14 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MIN -2147483648
# define MAX 2147483647

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_putchar_fdp(char c, int fd);
int	ft_putint_fd(int n, int fd);
int	ft_putptr(void *ptr, int fd);
int	ft_putstr_fdp(char *str, int fd);
int	ft_putunsigned_fd(unsigned int num, int fd);
int	ft_putnbr_hex(int num, int fd, char c);

#endif
