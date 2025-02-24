/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:22:11 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 22:56:59 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Permet dinitier la liste.
 * 
 * @param history 
 */
void init_history(t_history *history)
{
    history->head = history->tail = history->current = NULL;
}

/**
 * @brief Permet d'ajouter un noeu a la liste.
 * 
 * @param history 
 * @param line 
 */
void ft_add_history(t_history *history, const char *line)
{
    t_historique *new_node;

    if (!line || !*line) // Ne pas ajouter une ligne vide
        return;

    new_node = malloc(sizeof(t_historique));
    if (!new_node)
        return;

    new_node->line = ft_strdup(line);
    new_node->next = NULL;
    new_node->prev = history->tail;

    if (history->tail)
        history->tail->next = new_node;
    else
        history->head = new_node; // Premier élément

    history->tail = new_node;

    // ✅ Corrigé : Réinitialiser `current` pour qu'on recommence depuis la fin
    history->current = NULL;
}

/**
 * @brief Permet de clear la liste.
 * 
 * @param history 
 */
void ft_rl_clear_history(t_history *history)
{
    t_historique *current;
    t_historique *next;
    
    current = history->head;
    while (current) {
        next = current->next;
        free(current->line);
        free(current);
        current = next;
    }
    history->head = history->tail = history->current = NULL;
}
