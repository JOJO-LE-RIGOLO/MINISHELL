/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:58:24 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/25 17:47:20 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char *clean_arg(char *arg)
{
    int i = 1, j = 1;
    int l = (int)ft_strlen(arg);
    char *cleaned;

    cleaned = ft_calloc(sizeof(char), l - i + 1);
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
        {
            ft_printf("ERROR: Memory allocation failed\n");
            return;
        }
        free(args[i]);
        args[i] = ft_strtrim(tmp, charset);
        if (is_type(args[i]) == arg)
        {
            free(args[i]);
            args[i] = tmp;
        }
        i++;
    }
}
