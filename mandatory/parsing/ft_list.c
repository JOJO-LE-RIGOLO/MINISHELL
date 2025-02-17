/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:21:40 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/17 17:03:37 by jotudela         ###   ########.fr       */
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
	if (tr->is_pipe)
		free(tr->is_pipe);
	if (tr->path)
		free(tr->path);
	if (tr->args)
		ft_cleartab(tr->args);
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

char	**split_args(t_commands *li, char **args, int *i)
{
	char	*tmp;
	char	*cmd;
	char	**cmd_args;

	tmp = ft_strjoin(args[0], " ");
	if (!tmp)
		return (NULL);
	while (li->index < *i)
	{
		cmd = ft_strjoin(tmp, args[li->index]);
		if (!cmd)
			return (free(tmp), NULL);
		free(tmp);
		if (args[li->index + 1])
			tmp = ft_strjoin(args[li->index + 1], " ");
		if (!tmp)
			return (free(cmd), NULL);
		li->index++;
	}
	cmd_args = ft_split(cmd, ' ');
	if (!cmd_args)
		return (free(cmd), free(tmp), NULL);
	free(tmp);
	return (cmd_args);
}

t_tree    *new_node(t_commands *li, char **args, char **envp, int *i)
{
	t_tree    *tr;

    tr = ft_calloc(sizeof(*tr), 1);
	write(1, "o1\n", 4);
    if (!tr)
    {
        ft_putendl_fd("Erreur allocation memoire.", 2);
        exit(EXIT_FAILURE);
    }
	if (li->mod == 1)
	{
    	tr->path = ft_find_cmd(args[0]);
		write(1, "o2\n", 4);
		tr->args = split_args(li, args, i);
		write(1, "o3\n", 4);
	}
	else
	{
		tr->path = ft_find_cmd(args[li->index]);
		write(1, "o4\n", 4);
		tr->args = split_args(li, args + li->index, i);
		write(1, "o5\n", 4);
	}
	tr->env = envp;
	tr->is_pipe = NULL;
    tr->tleft = NULL;
    tr->tright = NULL;
    tr->parent = li->root;
    return (tr);
}

t_commands	*ft_lstnew(char **args, char **envp, int *i, int mod)
{
	t_commands	*li;

	li = ft_calloc(sizeof(*li), 1);
	if (!li)
		return (NULL);
	li->index = 0;
	li->mod = mod;
	li->root = new_tree(args[*i]);
	if (mod == 1)
	{
		li->root->tleft = new_node(li, args, envp, i);
		li->root->tright = new_node(li, args, envp, i);
	}
	else
	{
		li->root->tleft = NULL;
		li->root->tright = new_node(li, args, envp, i);
	}
	li->index = *i + 1;
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