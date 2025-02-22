/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:33:39 by jojo              #+#    #+#             */
/*   Updated: 2025/02/22 21:34:33 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    my_echo(char *opt, char *str)
{
    if (opt)
    {
        if (ft_strncmp(opt, "-n", ft_strlen("-n")) == 0)
        {
            if (str)
                return (ft_putstr_fd(str, 1));
            return ;
        }
    }
    ft_putendl_fd(opt, 1);
}
