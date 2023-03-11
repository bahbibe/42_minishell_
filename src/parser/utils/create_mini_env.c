/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mini_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 16:57:42 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/03 18:52:34 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_strrchr(char *str, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			j = i;
		i++;
	}
	if (str[j] == c)
		return (j);
	return (-1);
}

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	create_env(char **env)
{
	int		i;
	char	*value;

	i = 0;
	while (env && env[i])
	{
		if (ft_strchr(env[i], '=') == -1)
			value = 0;
		else
			value = ft_substr(env[i],
					(ft_strchr(env[i], '=') + 1), ft_strlen(env[i]));
		env_create_node(ft_substr(env[i], 0, ft_strchr(env[i], '=')),
			value);
		i++;
	}
}
