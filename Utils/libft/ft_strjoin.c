/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#             */
/*   Updated: 2024/11/06 16:46:55 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	total_len(char const *s1, char const *s2)
{
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	return (len);
}

static void	ft_strcat(char *str, char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = total_len(s1, s2);
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	ft_strcat(str, s1, s2);
	return (str);
}
