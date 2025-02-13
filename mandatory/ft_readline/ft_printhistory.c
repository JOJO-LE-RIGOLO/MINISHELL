/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhistory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:34:57 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/09 16:36:32 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Permet l'affichage du prompt et de la commande.
 * 
 * @param line 
 */
void print_line(const char *line)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(line) + ft_strlen(Hello);
    while (i < len)//permet de suprimer tout ce qu'il y a sur le terminal
    {
        write(STDOUT_FILENO, "\b \b", 3);
        i++;
    }
    write(STDOUT_FILENO, "\r", 1);  // Réafficher l'invite de commande
    write(STDOUT_FILENO, Hello, ft_strlen(Hello));
    write(STDOUT_FILENO, line, ft_strlen(line));
}

void ft_rl_on_new_line()
{
    write(STDOUT_FILENO, "\n", 1);
}

void ft_rl_replace_line(const char *new_line)
{
    write(STDOUT_FILENO, "\r", 1);
    write(STDOUT_FILENO, new_line, strlen(new_line));
}

void ft_rl_redisplay()
{
    write(STDOUT_FILENO, "\r", 1);
    write(STDOUT_FILENO, Hello, ft_strlen(Hello));
}
