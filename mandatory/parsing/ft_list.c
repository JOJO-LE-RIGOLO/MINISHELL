/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:40 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/14 12:53:37 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_cleartab(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        free(args[i]);
        i++;
    }
    free(args);
    args = NULL;
}

void    clean_tree(t_tree *tr)
{
    if (!tr)
        return ;
    clean_tree(tr->tleft);
    clean_tree(tr->tright);
    free(tr);
}

void	ft_lstclear(t_commands **lst)
{
	t_commands	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		clean_tree((*lst)->root);
		free(*lst);
		*lst = tmp;
	}
}

t_tree    *new_tree(char *operation)
{
    t_tree    *tr;

    tr = ft_calloc(sizeof(*tr), 1);
    if (!tr)
    {
        ft_putendl_fd("Erreur allocation memoire.", 2);
        exit(EXIT_FAILURE);
    }
    tr->path = NULL;
	tr->args = NULL;
	tr->env = NULL;
	tr->is_pipe = ft_strdup(operation);
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = NULL;
    return (tr);
}

t_tree    *new_node(char **args, char **envp)
{
	t_tree    *tr;

    tr = ft_calloc(sizeof(*tr), 1);
    if (!tr)
    {
        ft_putendl_fd("Erreur allocation memoire.", 2);
        exit(EXIT_FAILURE);
    }
    tr->path = NULL;
	tr->args = NULL;
	tr->env = envp;
	tr->is_pipe = NULL;
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = NULL;
    return (tr);
}

t_commands	*ft_lstnew(char **args, char **envp, int *i, int mod)
{
	t_commands	*li;

	li = ft_calloc(sizeof(*li), 1);
	if (!li)
		return (NULL);
	li->root = new_tree(args[*i]);
	if (mod == 1)
	{
		li->root->tleft = new_node(args, envp);
		li->root->tright = new_node(args, envp);
	}
	else
	{
		li->root->tleft = NULL;
		li->root->tright = new_node(args, envp);
	}
	li->next = NULL;
	return (li);
}

t_commands	*ft_lstlast(t_commands *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_commands **lst, t_commands *new)
{
	t_commands	*li;

	if (!lst || !new)
		msg_error("lst or new, problem");
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}