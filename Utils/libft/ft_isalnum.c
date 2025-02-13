/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/06 16:46:21 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_lowercase(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	ft_is_uppercase(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static int	ft_is_al(int c)
{
	if (ft_is_lowercase(c) == 1 || ft_is_uppercase(c) == 1)
		return (1);
	return (0);
}

static int	ft_is_num(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_is_al(c) == 1 || ft_is_num(c) == 1)
		return (1);
	return (0);
}
