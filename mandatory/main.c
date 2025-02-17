/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:16:42 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/17 14:49:41 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

/**
 * @brief Fonction juste pour voir si je recupere toute la ligne de commande
 * 
 */
/*void    print_args(char **args)
{
    int i;

    i = 0;
    while (args[i])
    {
        printf("%s\n", args[i]);
        i++;
    }
}

void    print_lst(t_commands *li)
{
    while (li)
    {
        if (li->root->is_pipe)//affichage du pipe
            printf("%s\n", li->root->is_pipe);

        if (li->root->tleft->path)//affichage de la branche de gauche
            printf("%s\n", li->root->tleft->path);
        if (li->root->tleft->args)
            print_args(li->root->tleft->args);

        printf("\n");

        if (li->root->tright->path)//affichage de la branche de droite
            printf("%s\n", li->root->tright->path);
        if (li->root->tright->args)
            print_args(li->root->tright->args);
        
        li = li->next;
    }
}*/

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
    //t_commands  *list;
    char        **args;

    (void)envp;
    if (ft_strncmp(line, "exit", ft_strlen("exit")) == 0) //si l'utilisateur rentre "exit"
    {
        ft_rl_clear_history(h);
        write(STDOUT_FILENO, Hello, ft_strlen(Hello));
        write(STDOUT_FILENO, "bye 👋 !\n", 12);
        disableRawMode();
        exit(0);
    }
    args = ft_split(line, ' ');
    //print_args(args);
    /*if (args)
    {
        list = ft_ultimate_parse(args, envp);
        if (!list)
            return (ft_cleartab(args));
        //print_lst(list);
        //ft_cleanning(list);
        //ft_start(&h, list);
        ft_cleartab(args);
        ft_lstclear(&list);
    }*/
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
        write(1, Hello, ft_strlen(Hello));
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
