/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:43:19 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/09 09:46:06 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	exit_error(char *str)
{
	ft_error("exit\n", 1);
	ft_error("Minishell: ", 255);
	ft_error(str, 255);
	ft_error(": numeric argument required\n", 255);
}

int	check_exit(char *nb)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (nb[++i])
		if (nb[i] == '-' || nb[i] == '+')
			j++;
	if (j > 1)
		return (exit_error(nb), 0);
	i = -1;
	while (nb[++i])
		if (!((nb[i] >= '0' && nb[i] <= '9') || nb[i] == '+' || nb[i] == '-'))
			return (exit_error(nb), 0);
	if (nb[i - 1] == '+' || nb[i - 1] == '-')
		return (exit_error(nb), 0);
	return (1);
}

void	exit_cmd(char **args)
{
	if (args[1] && !check_empty(args[1]))
		return (exit_error(args[1]), ft_error("exit\n", 1), exit(255));
	if (args[1] && !check_exit(args[1]))
		exit(255);
	if (args[1] && !args[2])
	{
		if (!g_global.head->next)
			printf("exit\n");
		exit((unsigned char)ft_atoi(args[1]));
	}
	if (!args[1])
	{
		if (!g_global.head->next)
			printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_error("exit\n", 1);
		ft_error("exit: too many arguments\n", 1);
	}
}
