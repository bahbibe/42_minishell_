/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahbibe <bahbibe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:02:19 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/06 21:38:33 by bahbibe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_pipes_len(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			while (line[i + 1] && line[++i] != '\'')
				;
		else if (line[i] == '"')
			while (line[i + 1] && line[++i] != '\"')
				;
		if (line[i] == '|')
			j++;
		i++;
	}
	return (j);
}

int	check_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '	')
			return (1);
		i++;
	}
	return (0);
}

int	check_pipes(char *line)
{
	int		i;
	int		pipes_len;
	char	**temp;
	int		j;

	j = 0;
	temp = ft_split_costom(line);
	pipes_len = get_pipes_len(line);
	if (pipes_len > 0 && !temp)
		return (0);
	i = 0;
	while (temp[i])
	{
		if (check_word(temp[i]))
			j++;
		i++;
	}
	tab_free(temp);
	if (j != pipes_len + 1)
		return (0);
	return (1);
}

int	check_empty(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (line[i] != ' ' && line[i] != '	')
			return (1);
	if (!line[i])
		return (0);
	return (1);
}

int	check_syntax(char *line)
{
	if (!check_pipes(line))
		return (0);
	return (1);
}
