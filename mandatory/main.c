/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 22:58:25 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

void print_tree(t_tree *node, int level)
{
    if (node == NULL)
        return;

    // Afficher l'indentation pour représenter la profondeur de l'arbre
    for (int i = 0; i < level; i++) {
        printf("  ");
    }

    // Afficher le type du nœud et son adresse
    printf("Nœud: %p %i\n", node, node->type);

    // Si le nœud a un enfant gauche, afficher récursivement
    if (node->tleft) {
        print_tree(node->tleft, level + 1);
    }

    // Si le nœud a un enfant droit, afficher récursivement
    if (node->tright) {
        print_tree(node->tright, level + 1);
    }
}

void    pirnt_tokens(t_tokens *t)
{
    while (t)
    {
        ft_printf("%s %i\n", t->str, t->type);
        t = t->next;
    }
}

/**
 * @brief Permet de regarder si l'utilisateur met exit et ce n'est pas le cas
 * je parse ma/mes commande(s) et je l'envoie a executer.
 * 
 * @param h 
 * @param line 
 * @param envp 
 */
void    handle_imput(t_history *h, char *line, char **envp)
{
    char        **args;
    //t_tree      *commands;
    t_tokens    *tokens;

    if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0) //si l'utilisateur rentre "exit"
        my_exit(h);
    args = ft_split(line, ' ');
    if (!args)
        return ;
    clean_args(args);
    if (builtins(args, envp) == 1)
        return (free_tab(args));
    tokens = tokeniser(args);
    if (!tokens)
        return (free_tab(args));
    free_tab(args);
    pirnt_tokens(tokens);
    //commands = parsing_ast(tokens->next, envp);
    //print_tree(commands, 0);
    //exec(commands);
    return (ft_lstclear(&tokens)/*, clear_ast(commands)*/);
}

/**
 * @brief Bah c'est le main mon reuf.
 * 
 * @param ac 
 * @param av 
 * @param envp 
 * @return int 
 */
int main(int ac, char **av, char **envp)
{
    t_history h;

    (void)av;
    if (ac != 1)
        return (write(2, "Error\nFormat to execute : ./minishell", 38));
    init_history(&h);
    enableRawMode();
    setup_signals();
    while (1)
    {
        print_prompt(NULL);
        ft_readline(&h);
        if (!h.head || !h.head->line)
        {
            printf("bye 👋 !\n");
            ft_rl_clear_history(&h); // Nettoyage de l'historique avant de quitter
            disableRawMode();
            exit(0);
        }
        if (!*(h.head->line)) //si l'utilisateur ne met rien
            continue ;
        handle_imput(&h, h.tail->line, envp);
    }
}
