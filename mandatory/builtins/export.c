/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:59:10 by jojo              #+#    #+#             */
/*   Updated: 2025/02/22 23:46:11 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    export(char **envp)
{
    int i;

    i = 0;
    while (envp[i])
    {
        ft_putstr_fd("declare -x ", 1);
        ft_putendl_fd(envp[i], 1);
        i++;
    }
}
