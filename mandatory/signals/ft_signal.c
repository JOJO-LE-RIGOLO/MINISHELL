/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 15:41:39 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 22:19:58 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_signals(int signum)
{
	(void)signum;
	if (waitpid(-1, NULL, WNOHANG) == -1)
	{
		write(STDOUT_FILENO, "^C\n", 3);
		print_prompt(NULL);
	}
}

void	sigquit_handler(int signum)
{
	(void)signum;
}

void setup_signals(void)
{
    signal(2, handle_signals);
	signal(3, sigquit_handler);
}
