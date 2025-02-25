/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:58:24 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/25 11:34:39 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char *clean_arg(char *arg)
{
    int i = 0, j = 0;
    int l = (int)ft_strlen(arg);
    char *cleaned;

    if ((arg[0] == '"' || arg[0] == '\'') && (arg[l - 1] == '"' || arg[l - 1] == '\''))
    {
        i = 1;
        l -= 1;
    }
    cleaned = ft_calloc(sizeof(char), l - i + 1);
    if (!cleaned)
        return (NULL);
    while (i < l)
    {
        if (arg[i] != '\'' && arg[i] != '"')
            cleaned[j++] = arg[i];
        i++;
    }
    cleaned[j] = '\0';
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
        {
            ft_printf("ERROR: Memory allocation failed\n");
            return;
        }
        free(args[i]);
        args[i] = ft_strtrim(tmp, charset);
        free(tmp);
        if (!args[i])
        {
            ft_printf("ERROR: Memory allocation failed in ft_strtrim\n");
            return;
        }
        i++;
    }
}
