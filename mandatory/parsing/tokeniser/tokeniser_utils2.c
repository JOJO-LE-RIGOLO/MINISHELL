/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokeniser_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 10:23:21 by jojo              #+#    #+#             */
/*   Updated: 2025/02/24 14:37:12 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int ft_verif_type(t_tokens *lst)
{
    if (!lst || !lst->type || !lst->str || lst->type < 0)
        return (1);
    return (0);
}
