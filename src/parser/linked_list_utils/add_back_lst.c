/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 14:00:39 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/02/25 11:20:08 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	add_back_lst(t_lexer_node **head, t_lexer_node *node)
{
	t_lexer_node	*current;

	current = *head;
	if (!current)
		*head = node;
	else
	{
		while (current->next)
			current = current->next;
		current->next = node;
	}
	node->next = 0;
}

void	files_add_back_lst(t_files	*head, t_files *node)
{
	while (head->next)
		head = head->next;
	head->next = node;
	node->next = 0;
}

void	env_add_back_lst(t_mini_env	*head, t_mini_env *node)
{
	while (head->next)
		head = head->next;
	head->next = node;
	node->previous = head;
	node->next = 0;
}
