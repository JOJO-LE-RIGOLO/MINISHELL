/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/06 16:47:04 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_good(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (0);
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	end = ft_strlen(s1);
	while (is_good(s1[start], set) == 0)
		start++;
	if (start == ft_strlen(s1))
	{
		str = ft_strdup("");
		if (!str)
			return (0);
		else
			return (str);
	}
	while (is_good(s1[end - 1], set) == 0)
		end--;
	str = ft_substr(s1, start, end - start);
	return (str);
}
