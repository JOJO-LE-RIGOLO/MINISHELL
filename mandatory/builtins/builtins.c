/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:14:59 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/20 15:25:28 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int    builtins(char *line, char **args)
{
    if (ft_strncmp(line, "pwd", ft_strlen("pwd")) == 0)
        return (pwd(), 1);
    if (ft_strncmp(line, "cd", ft_strlen("cd")) == 0)
        return (cd(args[1]), 1);
    if (ft_strncmp(line, "echo", ft_strlen("echo")) == 0)
        return (my_echo(args[1], args[2]), 1);
    return (0);
}