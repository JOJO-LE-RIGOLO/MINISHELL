/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:28:35 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/21 10:36:41 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_lstclear(t_tokens **lst)
{
	t_tokens	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str);
		free(*lst);
		*lst = tmp;
	}
}

t_tokens	*ft_lstlast(t_tokens *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_tokens **lst, t_tokens *new)
{
	t_tokens	*li;

	if (!lst || !new)
		return ;
	li = ft_lstlast(*lst);
	if (!li)
		*lst = new;
	else
		li->next = new;
}

t_tokens	*ft_lstnew(char *content, int type)
{
	t_tokens	*li;

	li = malloc(sizeof(*li));
	if (!li)
		return (NULL);
    li->type = type;
	li->str = ft_strdup(content);
    if (!li->str)
        return (NULL);
	li->next = NULL;
	return (li);
}

t_tokens    *tokeniser(char **args)
{
    int i;
    t_tokens    *list;

    i = 0;
    list = ft_lstnew("", -1);
    while (args[i])
    {
        ft_lstadd_back(&list, ft_lstnew(args[i], is_type(args[i])));
        if (ft_verif_type(list) == 1)
		{
			ft_lstclear(&list);
			return (NULL);
		}
		i++;
    }
	return (list);
}
