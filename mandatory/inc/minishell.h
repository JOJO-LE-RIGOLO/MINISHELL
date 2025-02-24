/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:01:53 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 22:56:47 by jojo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PATH_MAX 4096
# define CLEAR_LINE "\033[2K\r"
# define CURSOR_BACKWARD "\033[D"

# include "../../Utils/libft/libft.h"
# include "../../Utils/ft_printf/ft_printf.h"
# include "../../Utils/get_next_line/get_next_line_bonus.h"

# include <stdio.h>          // printf, perror
# include <stdlib.h>         // malloc, free, getenv, exit
# include <unistd.h>         // write, access, read, close, fork, getcwd, chdir, pipe, isatty, ttyslot
# include <readline/readline.h> // readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay
# include <readline/history.h>  // add_history
# include <fcntl.h>          // open
# include <sys/wait.h>       // wait, waitpid, wait3, wait4
# include <signal.h>         // signal, sigaction, sigemptyset, sigaddset, kill
# include <sys/stat.h>       // stat, lstat, fstat
# include <dirent.h>         // opendir, readdir, closedir
# include <string.h>         // strerror
# include <termios.h>        // tcsetattr, tcgetattr
# include <sys/ioctl.h>      // ioctl
# include <curses.h>         // tgetent, tgetflag, tgetnum, tgetstr
# include <term.h>           // tgoto, tputs
# include <limits.h>

typedef enum s_node
{
    input,// <
    output,// >
    here_doc,// <<
    output_append,// >>
    PIPE,// |
    double_pipe,// ||
    environnement_var,// $
    val_output_cmd,// &?
    double_and,// &&
    command,// cat
    opt,// -l
    arg,// tout le reste
    file,// file1
}           type_node;

/* Liste chainee pour les tokens */
typedef struct s_tokens
{
    char        *str;
    type_node   type;
    struct s_tokens    *next;
    struct s_tokens    *prev;
}           t_tokens;

/* Structure qui va tout recuperer et tout executer */
typedef struct s_tree
{
    char            *path;
    char            **args;
    char            **env;
    char            *file;
    char            *rediction;
    type_node       type;
    struct s_tree *tleft;
    struct s_tree *tright;
    struct s_tree *parent;
}           t_tree;

/* Structures pour l'Historique et le terminal */
typedef struct s_historique
{
    char    *line;
    struct s_historique *next;
    struct s_historique *prev;
}           t_historique;

typedef struct 
{
    t_historique *head;
    t_historique *tail;
    t_historique *current;
}           t_history;

/* Fonctions pour les signaux */
void    setup_signals(void);
void    sigquit_handler(int signum);
void    handle_signals(int signum);

/* Fonctions pour l'Historique et le Terminal */
char    *ft_readline(t_history *history);
void    print_prompt(t_history *h);
void    init_history(t_history *history);
void    ft_rl_clear_history(t_history *history);
void    ft_rl_on_new_line(void);
void    ft_rl_replace_line(const char *new_line);
void    ft_rl_redisplay(void);
void    print_line(const char *line, t_history *h);
void    ft_add_history(t_history *history, const char *line);
void    disableRawMode(void);
void    enableRawMode(void);

/* Fonctions de Parsing */
t_tree      *parsing_ast(t_tokens *tokens, char **envp);
t_tree      *create_tree(char **envp);
int         update_tree(t_tree **node, t_tokens *token);
void        clear_ast(t_tree *commands);

/* Fonctions poour netoyer chaque arguments */
void        clean_args(char **args);
char        *clean_arg(char *arg);

/** Fonctions pour tokeniser **/
t_tokens    *tokeniser(char **args);
t_tokens	*ft_lstnew(char *content, int type);
void        ft_lstadd_back(t_tokens **lst, t_tokens *new);
t_tokens	*ft_lstlast(t_tokens *lst);
void        ft_lstclear(t_tokens **lst);
int         is_type(char *str);
int         is_file(char *file);
int         is_command(char *cmd);
int         ft_verif_type(t_tokens *lst);

/* Fonctions pour Executer */

/* Builtins */
int     builtins(char **args, char **envp);
void    pwd(void);
void    cd(char *path);
void    my_echo(char *opt, char *str);
void    env(char **envp);
void    export(char **envp);

/* Utils */
char    *pwd2(void);
void    free_tab(char **args);
void    my_exit(t_history *h);
char	*ft_find_cmd(char *cmd);
void    print_var(char *src, int mod);
void    print_unless_quotes(char *str, int mod);

#endif