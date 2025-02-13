/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/06 16:46:26 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	size_t	i;
	char	c;
	size_t	size;

	i = 0;
	size = ft_strlen(str);
	while (i < size / 2)
	{
		c = str[size - 1 - i];
		str[size - 1 - i] = str[i];
		str[i] = c;
		i++;
	}
	return (str);
}

static size_t	total_len(int n)
{
	size_t	len;

	if (n == 0)
		return (1);
	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_nnot_good(int n)
{
	char	*str;

	if (n == 0)
	{
		str = ft_calloc(2, sizeof(char));
		if (str)
			str[0] = '0';
		return (str);
	}
	if (n == -2147483648)
	{
		str = ft_calloc(12, sizeof(char));
		if (str)
			ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	int		neg;
	char	*str;

	if (n == 0 || n == -2147483648)
		return (ft_nnot_good(n));
	neg = n < 0;
	if (n < 0)
		n *= -1;
	len = total_len(n) + neg;
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (n != 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	if (neg)
		str[len - 1] = '-';
	return (ft_strrev(str));
}
