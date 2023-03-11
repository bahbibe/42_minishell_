/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:38:39 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/05 17:08:09 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	env_search(char *variable)
{
	t_mini_env	*current;

	current = g_global.env_head;
	while (current)
	{
		if (ft_strcmp(current->name, variable))
			return (1);
		current = current->next;
	}
	return (0);
}

void	sorted_print(t_mini_env *head)
{
	char		*alpha;
	t_mini_env	*temp;
	int			i;

	i = 0;
	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_abcdefghijklmnopqrstuvwxyz";
	while (alpha[i])
	{
		temp = head;
		while (temp)
		{
			if (temp->name[0] == alpha[i])
			{
				if (temp->value == 0)
					printf("declare -x %s\n", temp->name);
				else
					printf("declare -x %s=\"%s\"\n", temp->name, temp->value);
			}
			temp = temp->next;
		}
		i++;
	}
}

void	env_cmd(char c)
{
	t_mini_env	*current;

	current = g_global.env_head;
	if (c == 'x')
		sorted_print(current);
	else
	{
		while (current)
		{
			if (current->value)
				printf("%s=%s\n", current->name, current->value);
			current = current->next;
		}
	}
	g_global.error = 0;
}
