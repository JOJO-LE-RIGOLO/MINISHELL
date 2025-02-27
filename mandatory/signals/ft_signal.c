/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:41:39 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/27 16:38:29 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_signals(int signum)
{
	(void)signum;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		rl_replace_line("", 0);
		write(STDOUT_FILENO, "\n", 3);
        print_prompt(NULL);
		rl_on_new_line();
		rl_redisplay();
	}
}

void	sigquit_handler(int signum)
{
	(void)signum;
    write(1, CLEAR_LINE, 5);
    rl_replace_line("", 0);
    print_prompt(NULL);
	rl_on_new_line();
	rl_redisplay();
}

void setup_signals(void)
{
    signal(2, handle_signals);
	signal(3, sigquit_handler);
}
