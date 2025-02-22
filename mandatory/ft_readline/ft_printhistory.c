/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhistory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:34:57 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/22 21:43:48 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Permet l'affichage du prompt et de la commande.
 * 
 * @param line 
 */
void print_line(const char *line, t_history *h)
{
    print_prompt(h);
    write(STDOUT_FILENO, line, ft_strlen(line));
}

void ft_rl_on_new_line()
{
    write(STDOUT_FILENO, "\n", 1);
}

void ft_rl_replace_line(const char *new_line)
{
    write(STDOUT_FILENO, new_line, strlen(new_line));
}

void ft_rl_redisplay()
{
    print_prompt(NULL);
}
