/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:46:37 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/10 13:37:54 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchrg(char *s, int c);
char	*ft_strdupg(char *s);
size_t	ft_strleng(char *s);
void	ft_strcatg(char *str, char const *s1, char const *s2);
char	*ft_substrg(char *s, unsigned int start, size_t len);
char	*ft_strjoing(char *s1, char *s2);
char	*get_next_line(int fd);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);
char	*read_and_stash(int fd, char *stash);

#endif
