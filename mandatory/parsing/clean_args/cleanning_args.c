/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanning_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:58:24 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 17:12:55 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char *clean_arg(char *arg)
{
    int i = 0;
    int j = 0;
    int l = (int)strlen(arg);

    if (arg[0] == '"' && arg[l - 1] == '"')
    {
        i = 1;
        l -= 1;
    }
    while (i < l)
        arg[j++] = arg[i++];
    arg[j] = '\0';
    return (arg);
}

void    clean_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        args[i] = clean_arg(args[i]);
        i++;
    }
}
