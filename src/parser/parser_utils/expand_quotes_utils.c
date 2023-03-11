/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:46:14 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/06 22:10:32 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*smart_get_variable(char *str, int flag)
{
	t_get_variable_struct	utils;
	char					*error_num;

	utils.i = -1;
	utils.final = 0;
	utils.string = str;
	while (str[++(utils.i)])
	{
		if (flag && str[utils.i] == '$' && str[utils.i + 1] == '?' && ++utils.i)
		{
			error_num = ft_itoa(g_global.error);
			utils.final = ft_strjoin(utils.final, error_num);
			free(error_num);
		}
		else if (str[utils.i] == '$' && speciale_check(str[utils.i + 1]))
		{
			if (flag)
				dolar_work(&utils);
			else
				utils.final = strjoin_small(utils.final, str[utils.i]);
		}
		else
			utils.final = strjoin_small(utils.final, str[utils.i]);
	}
	return (utils.final);
}

char	*single_expand(t_lexer_node *node, int *nb)
{
	char	*final;

	node->expand_here_doc = 0;
	final = ft_strdup("");
	while (++*nb < node->lexer_size && node->lexer[*nb].type != '\'')
		final = ft_strjoin(final, node->lexer[*nb].content);
	return (final);
}

char	*double_expand(t_lexer_node *node, int *nb, int flag)
{
	char	*final;
	char	*temp;

	node->expand_here_doc = 0;
	final = ft_strdup("");
	while (++*nb < node->lexer_size && node->lexer[*nb].type != '"')
	{
		temp = smart_get_variable(node->lexer[*nb].content, flag);
		final = ft_strjoin(final, temp);
		free(temp);
	}
	return (final);
}

char	*join_string(t_lexer_node *node, int *nb, int flag)
{
	char	*final;
	char	*temp;

	final = 0;
	while (*nb < node->lexer_size
		&& tokens_check(node->lexer[*nb].type, nb))
	{
		if (node->lexer[*nb].type == '\'')
			temp = single_expand(node, nb);
		else if (node->lexer[*nb].type == '"')
			temp = double_expand(node, nb, flag);
		else
			temp = smart_get_variable(node->lexer[*nb].content, flag);
		if (++*nb && temp)
		{
			final = ft_strjoin(final, temp);
			free(temp);
		}
		if (ft_strcmp(final, "$") && *nb < node->lexer_size)
		{
			free(final);
			final = ft_strdup("");
		}
	}
	return (final);
}

int	tokens_check(char c, int *nb)
{
	if (c == '>' || c == '<' || c == 'S' || c == 'T')
		return (--*nb, 0);
	return (1);
}
