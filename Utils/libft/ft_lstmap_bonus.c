/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 10:24:37 by jojo              #+#    #+#             */
/*   Updated: 2024/11/07 11:12:38 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*transformed_content;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		transformed_content = f(lst->content);
		new_node = ft_lstnew(transformed_content);
		if (!new_node)
		{
			if (del && transformed_content)
				del(transformed_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
