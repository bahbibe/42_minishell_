/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:10:46 by bahbibe           #+#    #+#             */
/*   Updated: 2023/03/05 23:26:38 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	check_error(char *cmd)
{
	int	temp;

	if (ft_strchr(cmd, '/') == -1)
	{
		ft_error(cmd, 127);
		ft_error(": command not found\n", 127);
		exit(127);
	}
	if (access(cmd, X_OK))
	{
		perror(cmd);
		exit(126);
	}
	temp = open(cmd, O_DIRECTORY);
	if (temp != -1)
	{
		close(temp);
		ft_error(cmd, 126);
		ft_error(": is a directory\n", 126);
		exit(126);
	}
}

int	exit_stat(int stat)
{
	if (WIFEXITED(stat))
		return (WEXITSTATUS(stat));
	else if (WIFSIGNALED(stat))
		return (WTERMSIG(stat) + 128);
	return (0);
}
