/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:37:08 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/04 20:51:54 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	get_last_of_var(char *str)
{
	int	i;

	i = 0;
	if (str[0] >= '0' && str[0] <= '9')
		return (1);
	while (str[i])
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (i);
		i++;
	}
	return (i);
}

int	get_dolar(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i);
		++i;
	}
	return (i);
}

char	*strjoin_small(char *s1, char c)
{
	char	*final_str;
	int		total_len;
	int		i;

	i = 0;
	total_len = get_str_len(s1) + 1;
	final_str = ft_calloc(sizeof(char), (total_len + 2));
	if (!final_str)
		return (0);
	if (!s1)
		s1 = get_substring("", 0);
	ft_strcpy(final_str, s1);
	i = get_str_len(final_str);
	final_str[i] = c;
	final_str[i + 1] = 0;
	free(s1);
	return (final_str);
}

int	dolar_work(t_get_variable_struct *utils)
{
	utils->temp = get_substring(utils->string + (utils->i + 1),
			get_last_of_var(utils->string + (utils->i + 1)));
	utils->variable = get_variable_cmd(utils->temp);
	utils->i = utils->i + get_last_of_var(utils->string + (utils->i + 1));
	free(utils->temp);
	if (!utils->variable)
		return (0);
	utils->final = ft_strjoin(utils->final, utils->variable);
	return (1);
}

int	speciale_check(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9') || c == '_')
		return (1);
	return (0);
}
