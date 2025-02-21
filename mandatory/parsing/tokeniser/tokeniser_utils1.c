/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:19:33 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/21 11:42:01 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void    free_tab(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
    args = NULL;
}

static char	*ft_find_cmd(char *cmd)
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
			return (free(temp), free_tab(dirs), NULL);
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (!full_path)
			return (free(full_path), free_tab(dirs), NULL);
		if (access(full_path, X_OK) == 0)
			return (free_tab(dirs), full_path);
		free(full_path);
		i++;
	}
	return (free_tab(dirs), NULL);
}

static int is_command(char *cmd)
{
    char    *cmd_path;

    cmd_path = ft_find_cmd(cmd);
    if (!cmd_path)
        return (1);
    if (access(cmd_path, X_OK) == 0)
        return (free(cmd_path), 0);
    return (free(cmd_path), 1);
}

static int is_file(char *file)
{
    if (access(file, F_OK) == 0)
        return (0);
    return (1);
}

int is_type(char *str)
{
    if (ft_strncmp(str, "<", ft_strlen(str)) == 0)
        return (inpout);
    else if (ft_strncmp(str, ">", ft_strlen(str)) == 0)
        return (output);
    else if (ft_strncmp(str, "<<", ft_strlen(str)) == 0)
        return (here_doc);
    else if (ft_strncmp(str, ">>", ft_strlen(str)) == 0)
        return (output_append);
    else if (ft_strncmp(str, "|", ft_strlen(str)) == 0)
        return (PIPE);
    else if (ft_strncmp(str, "||", ft_strlen(str)) == 0)
        return (double_pipe);
    else if (ft_strncmp(str, "$", ft_strlen(str)) == 0)
        return (environnement_var);
    else if (ft_strncmp(str, "$?", ft_strlen(str)) == 0)
        return (val_output_cmd);
    else if (ft_strncmp(str, "&&", ft_strlen(str)) == 0)
        return (double_and);
    else if (is_command(str) == 0)
        return (command);
    else if (ft_strncmp(str, "-", ft_strlen(str)) == 0)
        return (opt);
    else if (is_file(str) == 0)
        return (file);
    return (arg);
}
