/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:46:30 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/20 11:44:17 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strleng(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcatg(char *str, char const *s1, char const *s2)
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

char	*clean_stash(char *stash)
{
	char	*new_stash;
	int		newline_pos;

	if (!stash)
		return (NULL);
	newline_pos = 0;
	while (stash[newline_pos] && stash[newline_pos] != '\n')
		newline_pos++;
	if (stash[newline_pos] == '\n')
		newline_pos++;
	if (newline_pos >= (int)ft_strleng(stash))
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_substrg(stash, newline_pos, ft_strleng(stash) - newline_pos);
	free(stash);
	return (new_stash);
}

char	*ft_substrg(char *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	size = ft_strleng(s);
	if (start >= size)
		return (malloc(1 * sizeof(char)));
	if (len > size - start)
		len = size - start;
	ptr = malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_strjoing(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strleng(s1) + ft_strleng(s2) + 1;
	str = malloc(len * sizeof(char));
	if (!str)
		return (NULL);
	ft_strcatg(str, s1, s2);
	return (str);
}
