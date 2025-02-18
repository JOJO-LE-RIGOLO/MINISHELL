/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:33:39 by jojo              #+#    #+#             */
/*   Updated: 2025/02/18 14:46:26 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    my_echo(char *opt, char *str)
{
    if (opt)
        if (ft_strncmp(opt, "-n", ft_strlen("-n")) == 0)
            return (ft_putstr_fd(str, 1));
    ft_putendl_fd(opt, 1);
}
