/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:00:35 by jojo              #+#    #+#             */
/*   Updated: 2025/02/27 16:42:01 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/minishell.h"

const char *pwd2(void)
{
    static char cwd[PATH_MAX + 3];  // On alloue un peu plus d'espace pour "$ " (+3 pour le terminator et "$ ")
    size_t len;

    if (getcwd(cwd, sizeof(cwd) - 3) != NULL)  // Laisser de la place pour "$ "
    {
        len = ft_strlen(cwd);
        cwd[len] = '$';       // Ajout du '$'
        cwd[len + 1] = ' ';   // Ajout de l'espace
        cwd[len + 2] = '\0';  // Terminaison de la chaîne
        return (cwd);
    }
    return (NULL);
}


void print_prompt(char *str)
{
    static int echo_n_active = 0;
    char *last_line;

    if (str)
    {
        last_line = clean_line(str);
        if (!last_line)
            return ;
        if (ft_strncmp(last_line, "echo -n", 8) == 0)
        {
            if (!echo_n_active)
            {
                if (str[8] == '$'
                    || (str[8] == '"' && str[9] == '$'))
                    print_var(str + 9, 2);
                else if (str[8] == '\'')
                    print_unless_quotes(last_line + 7, 2, 1);
                else
                    write(1, str + 8, ft_strlen(str + 8));
                echo_n_active = 1;
            }
        }
        free(last_line);
    }
    echo_n_active = 0;
}

void    my_exit(void)
{
    print_prompt(NULL);
    write(STDOUT_FILENO, "bye 👋 !\n", 12);
    rl_clear_history();
    exit(0);
}
