/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/27 17:18:47 by jotudela         ###   ########.fr       */
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

void    print_tokens(t_tokens *t)
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
void    handle_imput(char *line, char **envp)
{
    char        **args;
    //t_tree      *commands;
    t_tokens    *tokens;

    if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0) //si l'utilisateur rentre "exit"
        my_exit();
    args = ft_split(line, ' ');
    if (!args)
        return ;
    if (builtins(args, envp) == 1)
        return (free_tab(args));
    tokens = tokeniser(args);
    if (!tokens)
        return (free_tab(args)); 
    print_tokens(tokens);
    ft_lstclear(&tokens); // Clear tokens after printing
    //commands = parsing_ast(tokens->next, envp);
    //print_tree(commands, 0);
    //exec(commands);
    return (ft_lstclear(&tokens), free_tab(args)/*, clear_ast(commands)*/);
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
    char    *line;
    char    **env;

    (void)av;
    if (ac != 1)
        return (write(2, "Error\nFormat to execute : ./minishell", 38));
    setup_signals();
    env = envp;
    while (1)
    {
        line = readline(pwd2());  // Demande une entrée à l'utilisateur
        if (!line)  // Si l'entrée est NULL (Ctrl-D par exemple), on quitte
            my_exit();
        if (*line)  // Si l'utilisateur n'a pas rentré une ligne vide
        {
            add_history(line);  // Ajoute la ligne à l'historique
            handle_imput(line, env);
        }
        free(line);
    }
}
