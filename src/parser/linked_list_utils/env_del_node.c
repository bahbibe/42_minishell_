/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:41:54 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/06 21:50:24 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	env_del_node(char *variable)
{
	t_mini_env	*current;
	t_mini_env	*temp;

	current = g_global.env_head;
	while (current)
	{
		if (ft_strcmp(current->name, variable))
		{
			temp = current;
			if (current == g_global.env_head)
				g_global.env_head = current->next;
			else
			{
				(current->previous)->next = current->next;
				if (current->next)
					(current->next)->previous = current->previous;
			}
			free(temp->name);
			free(temp->value);
			free(temp);
			return ;
		}
		current = current->next;
	}
}
