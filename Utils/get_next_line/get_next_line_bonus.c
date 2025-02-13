/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:46:33 by jotudela          #+#    #+#             */
/*   Updated: 2024/11/20 11:44:10 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchrg(char *s, int c)
{
	size_t			i;
	unsigned char	*str1;

	i = 0;
	if ((unsigned char)c == 0)
		return ((char *)s + ft_strleng(s));
	str1 = (unsigned char *)s;
	while (str1[i])
	{
		if (str1[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strdupg(char *s)
{
	char	*ptr;
	int		i;

	ptr = malloc(sizeof(char) * (ft_strleng(s) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*extract_line(char *stash)
{
	char	*line;
	int		newline_pos;

	if (!stash)
		return (NULL);
	newline_pos = 0;
	while (stash[newline_pos] && stash[newline_pos] != '\n')
		newline_pos++;
	if (stash[newline_pos] == '\n')
		newline_pos++;
	line = ft_substrg(stash, 0, newline_pos);
	return (line);
}

char	*read_and_stash(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		read_bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stash)
		stash = ft_strdupg("");
	while (!ft_strchrg(stash, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes <= 0)
		{
			free(buffer);
			if (read_bytes < 0 || !*stash)
				return (free(stash), NULL);
			return (stash);
		}
		buffer[read_bytes] = '\0';
		temp = ft_strjoing(stash, buffer);
		free(stash);
		stash = temp;
	}
	return (free(buffer), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_stash(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
