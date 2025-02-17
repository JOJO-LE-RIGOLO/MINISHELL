/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:16:21 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/17 16:39:15 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_find_cmd(char *cmd)
{
	char	**dirs;
	char	*full_path;
	char	*temp;
	int		i;

	dirs = ft_split("/bin /usr/bin /usr/local/bin /opt/homebrew/bin"
			" /opt/homebrew/sbin /usr/sbin /sbin", ' ');
	i = 0;
	while (dirs[i])
	{
		temp = ft_strjoin(dirs[i], "/");
		if (!temp)
			return (free(temp), ft_cleartab(dirs), NULL);
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			return (free(full_path), ft_cleartab(dirs), NULL);
		if (access(full_path, X_OK) == 0)
			return (ft_cleartab(dirs), full_path);
		free(full_path);
		i++;
	}
	return (ft_cleartab(dirs), NULL);
}

void    msg_error(char *why)
{
    write(STDERR_FILENO, Hello, ft_strlen(Hello));
    ft_putendl_fd(why, 2);
}

int	ft_verif(t_commands **list, char *str)
{
	if ((*list) == NULL || (*list)->root == NULL)
	{
		ft_lstclear(list);
		msg_error(str);
		return (1);
	}
	return (0);
}

int	first_commands(char **args, int *i, int mod)
{
	*i = 0;
	while (args[*i])
	{
		if (ft_strchr(args[*i], '|'))
			return (*i);
		(*i)++;
	}
	if (mod == 2)
		return (*i);
	return (0);
}

t_commands  *ft_ultimate_parse(char **args, char **envp)
{
    t_commands  *li;
    int     i;

    i = first_commands(args, &i, 1);
    li = ft_lstnew(args, envp, &i, 1);
    if (ft_verif(&li, "Error list") == 1)
		return (NULL);
	while (args[i])
	{
		i = first_commands(args + i, &i, 2);
		ft_lstadd_back(&li, ft_lstnew(args, envp, &i, 2));
		if (ft_verif(&li, "Error list") == 1)
			return (NULL);
	}
    ft_cleartab(args);
    return (li);
}
