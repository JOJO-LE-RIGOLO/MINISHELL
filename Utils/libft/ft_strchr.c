/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/07 10:07:36 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	*str1;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strlen(s));
	str1 = (unsigned char *)s;
	while (str1[i])
	{
		if (str1[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
