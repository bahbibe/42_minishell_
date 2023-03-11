/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:37:53 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/05 17:02:16 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	echo_utils(char **args, int new)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (args[i + 1])
			printf("%s ", args[i]);
		else
			printf("%s", args[i]);
		i++;
	}
	if (new == 0)
		printf("\n");
}

void	echo_cmd(char **args)
{
	int	i;
	int	j;
	int	new;

	new = 0;
	i = 0;
	while (args[++i])
	{
		j = 0;
		if (args[i][j] == '-' && args[i][j + 1])
		{
			while (args[i][++j] == 'n')
				continue ;
			if (args[i][j])
				break ;
			new = 1;
		}
		else
			break ;
	}
	echo_utils(args + i, new);
	g_global.error = 0;
}
