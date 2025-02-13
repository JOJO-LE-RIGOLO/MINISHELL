/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/06 16:46:22 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_lower_alpha(int c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	ft_is_upper_alpha(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_is_lower_alpha(c) == 1 || ft_is_upper_alpha(c) == 1)
		return (1);
	return (0);
}
