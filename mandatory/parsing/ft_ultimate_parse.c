/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_parse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:16:21 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/12 20:35:20 by jotudela         ###   ########.fr       */
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

void	ft_verif(t_commands **list, char *str)
{
	if ((*list) == NULL || (*list)->root == NULL)
	{
		ft_lstclear(list);
		msg_error(str);
	}
}

t_commands  *ft_ultimate_parse(char *line, char **envp)
{
    t_commands  *li;
    char    **args;
    int     i;

    args = ft_split(line, ' ');
    i = 0;
    li = ft_lstnew(args, envp);
    ft_verif(&li, "Error list");
	while (args[i])
	{
		ft_lstadd_back(&li, ft_lstnew(args, envp));
		ft_verif(&li, "Error list");
	}
    ft_cleartab(args);
    return (li);
}
