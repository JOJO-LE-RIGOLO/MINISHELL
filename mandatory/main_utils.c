/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:35 by jojo              #+#    #+#             */
/*   Updated: 2025/02/22 22:19:47 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

char    *pwd2(void)
{
    static char cwd[PATH_MAX];  // Tableau pour stocker le chemin courant

    if (getcwd(cwd, sizeof(cwd)) != NULL)
        return (cwd);
    return (NULL);
}

void print_prompt(t_history *h)
{
    static int echo_n_active = 0;
    char *current_path;
    char *last_line;

    current_path = pwd2();
    if (h && h->tail && h->tail->line)
    {
        last_line = h->tail->line;
        if (ft_strncmp(last_line, "echo -n", 6) == 0)
        {
            if (!echo_n_active)
            {
                write(1, last_line + 8, ft_strlen(last_line + 8));
                echo_n_active = 1;
            }
        }
    }
    echo_n_active = 0;
    write(1, "\033[31m[", ft_strlen("\033[31m["));
    write(1, "\033[34m", ft_strlen("\033[34m"));
    write(1, current_path, ft_strlen(current_path));
    write(1, ">\033[31m]", ft_strlen(">\033[31m]"));
    write(1, "\033[0m ", ft_strlen("\033[0m "));
}

void    my_exit(t_history *h)
{
    ft_rl_clear_history(h);
    print_prompt(NULL);
    write(STDOUT_FILENO, "bye 👋 !\n", 12);
    disableRawMode();
    exit(0);
}
