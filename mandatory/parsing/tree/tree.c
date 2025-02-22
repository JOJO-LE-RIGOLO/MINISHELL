/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 13:41:02 by jotudela          #+#    #+#             */
/*   Updated: 2025/02/22 21:00:47 by jojo             ###   ########.fr       */
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

t_tree  *parsing_ast(t_tokens *tokens, char **envp)
{
    t_tree  *ast;
    t_tree  *tmp;
    t_tree  *current;

    ast = create_tree(envp); // racine de l'AST
    current = ast;
    tokens = tokens->next; // on commence après le premier token (peut-être un "commande")
    while (tokens)
    {
        if (is_redirect(tokens->type) != -1) // gestion des redirections
        {
            tmp = create_tree(envp); // créer un sous-arbre pour la redirection
            tmp->tleft = current; // assigner le sous-arbre à gauche du nœud actuel
            current->parent = tmp; // lier le nœud actuel comme parent du nouveau nœud
            current = tmp; // déplacer le pointeur current au nouveau nœud
        }
        else if (tokens->type == PIPE) // gestion des pipes
        {
            tmp = create_tree(envp); // créer un nœud pour le pipe
            tmp->tleft = current; // assigner le nœud courant à gauche du pipe
            current->parent = tmp; // lier le nœud courant comme parent du nœud pipe
            current = tmp; // mettre à jour current pour le pipe
        }
        tokens = tokens->next; // passer au token suivant
    }
    return ast; // retourner l'arbre complet
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
