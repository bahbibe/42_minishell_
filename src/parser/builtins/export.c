/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 11:39:02 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/05 22:07:57 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	export_errors(char *name)
{
	ft_error("Minishell: export: ", 1);
	ft_error(name, 1);
	free(name);
	ft_error(": not a valid identifier\n", 1);
}

int	check_export_syntax(char *str)
{
	int	i;

	i = 0;
	if (!((str[i] >= 'a' && str[i] <= 'z')
			|| (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] == '_')))
		return (0);
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')
				|| (str[i] == '_')))
			return (0);
		i++;
	}
	return (1);
}

void	loop_export(char *arg)
{
	int			len;
	char		*name;
	char		*value;

	len = ft_strchr(arg, '=');
	if (len == -1)
		len = ft_strlen(arg);
	if (arg[0] == '=')
		return (ft_error("Minishell: export: `=': not a valid identifier\n", 1));
	name = get_substring(arg, len);
	if (!check_export_syntax(name))
		return (export_errors(name));
	value = 0;
	if (arg[len])
		value = get_substring(arg + len + 1, ft_strlen(arg + len + 1));
	if (env_search(name))
	{
		modifie_variable(name, value);
		free(name);
		return (free(value));
	}
	env_create_node(name, value);
}

void	export_cmd(char **args)
{
	int			i;

	g_global.error = 0;
	if (!args[1])
	{
		env_cmd('x');
		g_global.error = 0;
		return ;
	}
	i = 1;
	while (args[i])
	{
		loop_export(args[i]);
		i++;
	}
}
