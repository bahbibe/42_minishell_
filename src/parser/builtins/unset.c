/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:40:40 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/06 21:51:55 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	check_str(char *str)
{
	if (!((str[0] >= 'a' && str[0] <= 'z') || (str[0] >= 'A' && str[0] <= 'Z')
			|| str[0] == '_') || !check_empty(str))
	{
		ft_error("unset: ", 1);
		ft_error(str, 1);
		ft_error(": not a valid identifier\n", 1);
		return (0);
	}
	return (1);
}

void	unset_cmd(char **args)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if (!check_str(args[i]))
			return ;
		if (env_search(args[i]))
			env_del_node(args[i]);
		i++;
	}
	g_global.error = 0;
}
