/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:23:20 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/02/25 11:20:20 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

t_lexer_node	*lexer_create_node(t_lexer_node **head)
{
	t_lexer_node	*node;

	node = malloc(sizeof(t_lexer_node));
	add_back_lst(head, node);
	return (node);
}
