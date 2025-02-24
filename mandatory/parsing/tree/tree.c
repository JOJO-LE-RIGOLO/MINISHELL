/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:41:02 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/24 13:53:44 by jotudela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_tree  *create_tree(char **envp)
{
    t_tree  *node;

    node = ft_calloc(sizeof(*node), 1);
    if (!node)
        return (NULL);
    node->args = NULL;
    node->path = NULL;
    node->file = NULL;
    node->rediction = NULL;
    node->env = envp;
    node->tleft = NULL;
    node->tright = NULL;
    node->parent = NULL;
    return (node);
}

int is_redirect(type_node t)
{
    if (t == input)
        return (input);
    else if (t == output)
        return (output);
    else if (t == here_doc)
        return (here_doc);
    else if (t == output_append)
        return (output_append);
    return (-1);
}

static int  is_arg_or_file(t_tokens *t)
{
    //arg
    if (t->type == arg)
        return (arg);
    //file
    if (t->type == file)
        return (file);
    return (-1);
}

t_tree *parsing_ast(t_tokens *tokens, char **envp)
{
    if (!tokens || !envp)
        return NULL;

    t_tree *ast = NULL;
    t_tree *current = NULL;
    t_tokens *head = tokens;
    
    while (tokens && tokens->type != command)
        tokens = tokens->next;
    if (tokens)
    {
        t_tree *cmd = create_tree(envp);
        if (!cmd)
            return NULL;
        cmd->type = tokens->type;
        ast = cmd;
        current = ast;
    }
    tokens = head->next;
    while (tokens)
    {
        if (tokens && is_arg_or_file(tokens) != -1)
        {
            t_tree *file = create_tree(envp);
            if (!file)
            {
                clear_ast(ast);
                return NULL;
            }
            file->type = tokens->type;
            current->tright = file;
            file->parent = current;
        }
        if (is_redirect(tokens->type) != -1)
        {
            t_tree *redir = create_tree(envp);
            if (!redir)
            {
                clear_ast(ast);
                return NULL;
            }
            redir->type = tokens->type;
            if (current && current->type == command)
            {
                redir->tleft = current;
                if (current == ast)
                    ast = redir;
                else if (current->parent)
                    current->parent->tright = redir;
                redir->parent = current->parent;
                current->parent = redir;
                current = redir;
            }
        }
        else if (tokens->type == PIPE)
        {
            t_tree *pipe = create_tree(envp);
            if (!pipe)
            {
                clear_ast(ast);
                return NULL;
            }
            pipe->type = tokens->type;
            pipe->tleft = ast;
            ast->parent = pipe;
            ast = pipe;
            current = pipe;
            // Chercher la commande suivante
            tokens = tokens->next;
            while (tokens && tokens->type != command)
                tokens = tokens->next;
            if (tokens)
            {
                t_tree *cmd = create_tree(envp);
                if (!cmd)
                {
                    clear_ast(ast);
                    return NULL;
                }
                cmd->type = tokens->type;
                current->tright = cmd;
                cmd->parent = current;
                current = cmd;
            }
        }
        if (tokens)
            tokens = tokens->next;
    }
    return ast;
}

void    clear_ast(t_tree *commands)
{
    if (!commands)
        return ;
    clear_ast(commands->tleft);
    clear_ast(commands->tright);
    if (commands->path)
        free(commands->path);
    if (commands->args)
        free_tab(commands->args);
    if (commands->file)
        free(commands->file);
    if (commands->rediction)
        free(commands->rediction);
    free(commands);
}
