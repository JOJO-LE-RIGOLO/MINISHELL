/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 16:41:50 by jojo              #+#    #+#             */
/*   Updated: 2025/02/22 18:29:56 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int ft_tab_len(char **args)
{
    int i;

    i = 0;
    while (args[i])
        i++;
    return (i);
}

char    **ft_realloc_tab(char **args, char *new_line)
{
    int i;
    int len_tab;
    char    **new_tab;

    len_tab = ft_tab_len(args);
    new_tab = ft_calloc(sizeof(char **), len_tab + 1);
    if (!new_tab)
        return (NULL);
    i = 0;
    while (i < len_tab)
    {
        new_tab[i] = ft_strdup(args[i]);
        if (!new_tab[i])
            return (free_tab(new_tab), NULL);
        i++;
    }
    new_tab[i] = ft_strdup(new_line);
    if (!new_tab[i])
        return (free_tab(new_tab), NULL);
    i++;
    new_tab[i] = NULL;
    return (new_tab);
}

static int  update_command(t_tree **node, t_tokens *t)
{
    char    **tmp;

    if ((*node)->args)
    {
        tmp = ft_realloc_tab((*node)->args, t->str);
        if (!tmp)
            return (1);
        free_tab((*node)->args);
        (*node)->args = tmp;
        free_tab(tmp);
    }
    else
    {
        (*node)->args = ft_split(t->str, ' ');
        if (!(*node)->args)
            return (1);
    }
    if (!(*node)->path)
    {
        (*node)->path = ft_find_cmd(t->str);
        if (!(*node)->path)
            return (1);
    }
    return (0);
}

int     update_tree(t_tree **node, t_tokens *token)
{
    if (token->type == command || token->type == opt)
        if (update_command(node, token) == 1)
            return (1);
    return (0);
}
