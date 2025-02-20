/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:19:33 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/20 16:58:44 by jotudela         ###   ########.fr       */
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

int is_command(char *cmd)
{
    char    *cmd_path;
    char    *args[2];

    cmd_path = ft_find_cmd(cmd);
    if (!cmd_path)
        return (1);
    args[0] = cmd_path;
    args[1] = NULL;
    if (execve(cmd_path, args, NULL) != -1)
        return (free(cmd_path), 0);
    return (free(cmd_path), 1);
}

int is_type(char *str)
{
    if (ft_strncmp(str, "<", 1) == 0)
        return (inpout);
    else if (ft_strncmp(str, ">", 1) == 0)
        return (output);
    else if (ft_strncmp(str, "<<", 2) == 0)
        return (here_doc);
    else if (ft_strncmp(str, ">>", 2) == 0)
        return (output_append);
    else if (ft_strncmp(str, "|", 1) == 0)
        return (PIPE);
    else if (ft_strncmp(str, "||", 2) == 0)
        return (double_pipe);
    else if (ft_strncmp(str, "$", 1) == 0)
        return (environnement_var);
    else if (ft_strncmp(str, "$?", 2) == 0)
        return (val_output_cmd);
    else if (ft_strncmp(str, "&&", 2) == 0)
        return (double_and);
    else if (is_command(str) == 0)
        return (command);
    
}
