/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:34:10 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/03 19:01:38 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

void	skip_quotes(char *str, int *i)
{
	if (str[*i] == '\'')
		while (str[*i + 1] && str[++*i] != '\'')
			;
	else if (str[*i] == '"')
		while (str[*i + 1] && str[++*i] != '\"')
			;
}

int	get_element_size(char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] == '|')
		;
	while (str[i])
	{
		skip_quotes(str, &i);
		if (str[i] != '|' && (str[i + 1] == '|' || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

char	**ft_split_costom(char *str)
{
	char	**final;
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	final = ft_calloc(sizeof(char *), (get_element_size(str) + 1));
	while (str[++i] == '|')
		;
	j = i--;
	while (str[++i])
	{
		skip_quotes(str, &i);
		if (str[i] != '|' && (str[i + 1] == '|' || str[i + 1] == '\0'))
		{
			final[x++] = ft_substr(str, j, i - j + 1);
			j = i + 2;
		}
	}
	return (final);
}
