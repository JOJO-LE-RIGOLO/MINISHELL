/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:27:22 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/12 18:39:19 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 * @brief Permet de monter dans les anciennes commande dans le terminal.
 * 
 * @param history 
 * @param buffer 
 * @param pos 
 */
static void handle_arrow_up(t_history *history, char *buffer, int *pos)
{
    if (!history->tail)
        return ;
    if (!history->current)
        history->current = history->tail;
    else if (history->current->prev)
        history->current = history->current->prev;
    if (history->current)
        ft_strlcpy(buffer, history->current->line, BUFFER_SIZE);
    else
        buffer[0] = '\0';
    *pos = ft_strlen(buffer);
    print_line(buffer);
}

/**
 * @brief Permet de descendre dans les anciennes commande dans le terminal.
 * 
 * @param history 
 * @param buffer 
 * @param pos 
 */
static void handle_arrow_down(t_history *history, char *buffer, int *pos)
{
    if (!history->tail)
        return ;
    if (history->current && history->current->next)
        history->current = history->current->next;
    else
        history->current = NULL;
    write(1, "\33[2K\r", 5);
    if (history->current)
        ft_strlcpy(buffer, history->current->line, BUFFER_SIZE);
    else
        buffer[0] = '\0';
    *pos = ft_strlen(buffer);
    print_line(buffer);
}

/**
 * @brief Permet de diriger vers soit la gauche ou la droite et de faire doit
 * haut ou bas.
 * 
 * @param history 
 * @param buffer 
 * @param pos 
 * @param direction 
 */
static void handle_arrow_keys(t_history *history, char *buffer, int *pos, char direction)
{
    if (direction == 'A')
        handle_arrow_up(history, buffer, pos);
    else if (direction == 'B')
        handle_arrow_down(history, buffer, pos);
    else if (direction == 'C') // ➡ Flèche droite
    {
        if (*pos < (int)ft_strlen(buffer))
        {
            (*pos)++;
            write(STDOUT_FILENO, "\033[C", 3);
        }
    }
    else if (direction == 'D') // ⬅ Flèche gauche
    {
        if (*pos > 0)
        {
            (*pos)--;
            write(STDOUT_FILENO, "\033[D", 3);
        }
    }
}

/**
 * @brief Permet d'afficher dans le terminal de minishell les char envoyé.
 * 
 * @param buffer 
 * @param pos 
 * @param c 
 */
static int handle_character_input(char *buffer, int *pos, char c)
{
    int current_len;
    int i;

    if (!buffer || !pos)
        return (-1);
    current_len = (int)ft_strlen(buffer);
    if (current_len >= BUFFER_SIZE - 2)
        return (0);
    if (*pos < current_len)
        ft_memmove(&buffer[*pos + 1], &buffer[*pos], current_len - *pos);
    buffer[*pos] = c;
    (*pos)++;
    buffer[current_len + 1] = '\0';
    if (write(STDOUT_FILENO, CLEAR_LINE, 5) < 0 ||
        write(STDOUT_FILENO, Hello, ft_strlen(Hello)) < 0 ||
        write(STDOUT_FILENO, buffer, current_len + 1) < 0)
        return (-1);
    i = current_len + 1;
    while (i > *pos)
    {
        if (write(STDOUT_FILENO, CURSOR_BACKWARD, 3) < 0)
            return (-1);
        i--;
    }
    return (0);
}

/**
 * @brief Permet de suprimer du texte.
 * 
 * @param buffer 
 * @param pos 
 */
static int handle_backspace(char *buffer, int *pos)
{
    size_t remaining_len;
    size_t i;

    if (!buffer || !pos)
        return (-1);
    if (*pos <= 0)
        return (0);
    (*pos)--;
    remaining_len = ft_strlen(buffer + *pos);
    if (ft_memmove(&buffer[*pos], &buffer[*pos + 1], remaining_len) == NULL)
        return (-1);
    buffer[ft_strlen(buffer)] = '\0';
    if (write(STDOUT_FILENO, CLEAR_LINE, 5) < 0 ||
        write(STDOUT_FILENO, Hello, ft_strlen(Hello)) < 0 ||
        write(STDOUT_FILENO, buffer, ft_strlen(buffer)) < 0)
        return (-1);
    i = ft_strlen(buffer);
    while ((int)i > *pos)
    {
        if (write(STDOUT_FILENO, CURSOR_BACKWARD, 3) < 0)
            return (-1);
        i--;
    }
    return (0);
}

/**
 * @brief Pernet de recuperer ce que l'on ecrit et bien plus.
 * 
 * @param history 
 * @return char* 
 */
char *ft_readline(t_history *history)
{
    char buffer[BUFFER_SIZE];
    int pos = 0;
    char c;
    char seq[2];

    ft_memset(buffer, 0, BUFFER_SIZE);
    while (1)
    {
        if (read(STDIN_FILENO, &c, 1) != 1)
            continue;

        if (c == '\n')
        {
            buffer[ft_strlen(buffer)] = '\0';  // Terminer la ligne proprement
            write(STDOUT_FILENO, "\n", 1);
            if (pos == 0)  // Si la ligne est vide, on redessine le prompt
            {
                ft_rl_redisplay();
                continue;
            }
            ft_add_history(history, buffer);
            return (NULL);
        }
        if (c == 4)
        {
            if (pos == 0)
            {
                ft_rl_clear_history(history);
                printf("bye 👋 !\n");
                disableRawMode();
                exit(0);
            }
            continue;
        }
        if (c == 27 && read(STDIN_FILENO, &seq[0], 1) == 1 && read(STDIN_FILENO, &seq[1], 1) == 1 && seq[0] == '[')
        {
            handle_arrow_keys(history, buffer, &pos, seq[1]);
            continue;
        }
        if (c == 127)  
        {
            handle_backspace(buffer, &pos);
            continue;
        }
        handle_character_input(buffer, &pos, c);
    }
}
