/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:14:59 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 15:21:01 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int    builtins(char **args, char **envp)
{
    if (ft_strncmp(args[0], "pwd", ft_strlen("pwd")) == 0)
        return (pwd(), 1);
    if (ft_strncmp(args[0], "cd", ft_strlen("cd")) == 0)
        return (cd(args[1]), 1);
    if (ft_strncmp(args[0], "echo", ft_strlen("echo")) == 0)
        return (my_echo(args[1], args[2]), 1);
    if (ft_strncmp(args[0], "env", ft_strlen("env")) == 0)
        env(envp);
    if (ft_strncmp(args[0], "export", ft_strlen("export")) == 0)
        export(envp);
    return (0);
}
