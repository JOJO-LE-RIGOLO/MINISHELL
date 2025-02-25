/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:14:59 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/25 11:11:18 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int    builtins(char **args, char **envp)
{
    clean_args(args);
    if (ft_strncmp(args[0], "pwd", ft_strlen(args[0])) == 0)
        return (pwd(), 1);
    if (ft_strncmp(args[0], "cd", ft_strlen(args[0])) == 0)
        return (cd(args[1]), 1);
    if (ft_strncmp(args[0], "echo", ft_strlen(args[0])) == 0)
    {
        if (args[1] && args[2])
            return (my_echo(args[1], args[2]), 1);
        else if (args[1])
            return (my_echo(args[1], NULL), 1);
    }
    if (ft_strncmp(args[0], "env", ft_strlen(args[0])) == 0)
        env(envp);
    if (ft_strncmp(args[0], "export", ft_strlen(args[0])) == 0)
        export(envp);
    return (0);
}
