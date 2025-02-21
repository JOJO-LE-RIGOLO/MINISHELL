/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/21 11:45:05 by jojo             ###   ########.fr       */
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

void print_prompt(void)
{
    char *current_path = pwd2();
    
    if (current_path == NULL)
        return ;
    write(1, "\033[31m[", 7);
    write(1, "\033[34m", 6);
    write(1, current_path, ft_strlen(current_path));
    write(1, ">\033[31m]", 8);
    write(1, "\033[0m ", 6);
}

void    my_exit(t_history *h)
{
    ft_rl_clear_history(h);
    print_prompt();
    write(STDOUT_FILENO, "bye 👋 !\n", 12);
    disableRawMode();
    exit(0);
}

void    print_tokens(t_tokens *t)
{
    t_tokens    *tmp;

    tmp = t->next;
    write(1, "\n", 1);
    while (tmp)
    {
        ft_putnbr_fd(tmp->type, 1);
        write(1, "\n", 1);
        ft_putendl_fd(tmp->str, 1);
        tmp = tmp->next;
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

    (void)envp;
    if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0) //si l'utilisateur rentre "exit"
        my_exit(h);
    args = ft_split(line, ' ');
    if (!args)
        return ;
    if (builtins(line, args) == 1)
        return (free_tab(args));
    tokens = tokeniser(args);
    if (!tokens)
        return (free_tab(args));
    print_tokens(tokens);
    //commands = parsing_ast(tokens);
    //exec(commands);
    return (free_tab(args), ft_lstclear(&tokens)/*, clear_ast(commands)*/);
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
        print_prompt();
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
