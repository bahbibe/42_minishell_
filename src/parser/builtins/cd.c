/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:44:52 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/05 21:57:03 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	cd_utils(char *str)
{
	ft_error("Minishell: ", 1);
	ft_error(str, 1);
	ft_error(": No such directory\n", 1);
}

int	cd_work(char **args)
{
	int	folder;

	if (!args[1])
	{
		if (chdir(get_variable_cmd("HOME")))
			ft_error("Minishell: cd: HOME not set\n", 1);
	}
	else if (ft_strcmp(args[1], "-"))
	{
		if (!get_variable_cmd("OLDPWD"))
			ft_error("Minishell: cd: OLDPWD not set\n", 1);
		else
		{
			chdir(get_variable_cmd("OLDPWD"));
			get_builtin("pwd", (char *[1]){"pwd"});
		}
	}
	else
	{
		folder = chdir(args[1]);
		if (folder)
			return (cd_utils(args[1]), 0);
	}
	return (1);
}

void	cd_cmd(char **args)
{
	char	*temp;

	if (!cd_work(args))
		return ;
	modifie_variable("OLDPWD", get_variable_cmd("PWD"));
	temp = getcwd(0, 0);
	if (!temp)
	{
		perror("cd: error retrieving current \
directory: getcwd: cannot access parent directories");
		temp = ft_strjoin(0, get_variable_cmd("PWD"));
		temp = ft_strjoin(temp, "..");
		modifie_variable("PWD", temp);
	}
	else
		modifie_variable("PWD", temp);
	free(temp);
	g_global.error = 0;
}
