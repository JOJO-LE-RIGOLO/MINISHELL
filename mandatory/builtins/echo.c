/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:33:39 by jojo              #+#    #+#             */
/*   Updated: 2025/02/27 16:49:28 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void print_var(char *src, int mod)
{
    char *content;

    if (!src)
        return ;
    src = ft_strtrim(src, "$\"");
    content = getenv(src);
    if (!content)
    {
        ft_putstr_fd("Error: la variable ", 2);
        ft_putstr_fd(src, 2);
        ft_putendl_fd(" n'existe pas.", 2);
        free(src);
        return;
    }
    free(src);
    if (mod == 1)
        return (ft_putendl_fd(content, 1));
    ft_putstr_fd(content, 1);
}

void print_unless_quotes(char *str, int mod, int len)
{
    int i;

    i = 0;
    while (i++ < (int)ft_strlen(str) - len)
        if (str[i] != '\'' || str[i] != '"')
            write(1, &str[i], 1);
    if (mod == 1)
        ft_putchar_fd('\n', 1);
}

void    my_echo(char *opt, char *str)
{
    char    *trimmed;

    trimmed = clean_line(opt);
    if (!trimmed)
        return ;
    if (trimmed && str)
    {
        if (ft_strncmp(trimmed, "-n", ft_strlen(trimmed)) == 0)
        {
            if (str[0] == '$'
                || (str[0] == '"' && str[1] == '$'))
                return (free(trimmed), print_var(str, 2));
            else if (ft_strncmp(str, "'", ft_strlen("'")) == 0
                    || ft_strncmp(str, "\"", ft_strlen("\"")) == 0)
                return (free(trimmed), print_unless_quotes(str, 2, 2));
            return (free(trimmed), ft_putstr_fd(str, 1));
        }
    }
    free(trimmed);
    if (opt[0] == '$'
        || (opt[0] == '"' && opt[1] == '$'))
        return (print_var(opt, 1));
    else if (opt[0] == '\'')
        return (print_unless_quotes(opt, 1, 2));
    ft_putendl_fd(opt, 1);
}
