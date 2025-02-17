/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:47:00 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/17 13:55:28 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    cd(char *path)
{
    if (!path)
    {    
        write(2, "cd: There no path detected\n", 27);
        return ;
    }
    if (chdir(path) != 0)
    {
        ft_putstr_fd("cd: ", 2);
        ft_putstr_fd(path, 2);
        ft_putstr_fd(": No such file or directory\n", 2);
        return ;
    }
}
