/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/07 10:11:53 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str;

	i = ft_strlen(s);
	str = (unsigned char *)s;
	if ((unsigned char)c == 0)
		return ((char *)s + i);
	while (i > 0)
	{
		i--;
		if (str[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
