/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:58:24 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/27 10:48:14 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char *clean_line(char *line)
{
    int i = 0, j = 0;
    int l = (int)ft_strlen(line);
    char *cleaned;

    cleaned = ft_calloc(sizeof(char), l + 1);
    if (!cleaned)
        return (NULL);
    while (i < l - 1)
    {
        if (line[i] != '\'' && line[i] != '"')
            cleaned[j++] = line[i];
        i++;
    }
    cleaned[j] = '\0';
    return (cleaned);
}

char *clean_arg(char *arg)
{
    int i = 1, j = 1;
    int l = (int)ft_strlen(arg);
    char *cleaned;

    cleaned = ft_calloc(sizeof(char), l + 1);
    if (!cleaned)
        return (NULL);
    cleaned[0] = arg[0];
    while (i < l - 1)
    {
        if (arg[i] != '\'' && arg[i] != '"')
            cleaned[j++] = arg[i];
        i++;
    }
    cleaned[j] = arg[i];
    cleaned[j + 1] = '\0';
    return (cleaned);
}


void clean_args(char **args)
{
    char *tmp;
    char *charset;
    int i;

    i = 0;
    charset = "'\"";
    while (args[i])
    {
        tmp = clean_arg(args[i]);
        if (!tmp)
            return ((void)ft_printf("ERROR: Memory allocation failed\n"));
        free(args[i]);
        args[i] = ft_strtrim(tmp, charset);
        if (!args[i])
            return ((void)ft_printf("ERROR: Memory allocation failed\n"));
        if (is_type(args[i]) == arg)
        {
            free(args[i]);
            args[i] = tmp;
        }
        else
            free(tmp);
        i++;
    }
}
