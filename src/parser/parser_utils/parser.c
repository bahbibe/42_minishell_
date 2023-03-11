/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 20:17:45 by ybel-hac          #+#    #+#             */
/*   Updated: 2023/03/08 21:58:43 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	parser_work(t_lexer_node *node)
{
	int	i;
	int	j;

	node->cmd_struct.files_head = 0;
	j = 0;
	i = -1;
	node->cmd_struct.cmd = ft_calloc(sizeof(char *),
			parser_get_size(node) + 1);
	while (++i < node->lexer_size)
	{
		if (node->lexer[i].type == '<' || node->lexer[i].type == '>')
		{
			i = get_after_file(node, i);
			if (i <= 0)
				return (ft_error("Minishell: syntax error\n", 258), 0);
		}
		else if (node->lexer[i].type == '\'' || node->lexer[i].type == '"'
			|| node->lexer[i].type == 'W')
			node->cmd_struct.cmd[j++] = join_string(node, &i, 1);
		if (j && !(node->cmd_struct.cmd[j - 1]))
			j--;
		if (g_global.open_heredoc)
			return (0);
	}
	return (1);
}

int	check_env(char *cmd, char **paths)
{
	if (!paths)
	{
		free(cmd);
		return (0);
	}
	return (1);
}

char	*get_cmd_path(char *cmd)
{
	char	**paths;
	int		i;
	char	*final;

	i = -1;
	if (!cmd || *cmd == '/' || *cmd == '.')
		return (cmd);
	paths = ft_split(get_variable_cmd("PATH"), ":");
	if (!paths)
		return (cmd);
	if (!check_env(cmd, paths) || !ft_strlen(cmd))
		return (tab_free(paths), cmd);
	while (paths[++i])
	{
		final = ft_strjoin(ft_strdup(paths[i]), "/");
		final = ft_strjoin(final, cmd);
		if (access(final, X_OK) == 0)
		{
			tab_free(paths);
			return (free(cmd), final);
		}
		free(final);
	}
	return (tab_free(paths), cmd);
}

void	init_help(t_lexer_node *lexer_head)
{
	while (lexer_head)
	{
		lexer_head->cmd_struct.cmd = 0;
		lexer_head->cmd_struct.files_head = 0;
		lexer_head = lexer_head->next;
	}
}

int	parser_utils(t_lexer_node **lexer_head, char *line)
{
	t_lexer_node	*current;

	current = *lexer_head;
	init_help(*lexer_head);
	while (current)
	{
		current->temp_fd = -1;
		current->expand_here_doc = 1;
		if (!parser_work(current) || g_global.open_heredoc)
			return (parse_free(*lexer_head), 0);
		current = current->next;
		g_global.error = 0;
	}
	current = *lexer_head;
	while (current)
	{
		if (current->cmd_struct.cmd[0]
			&& !is_builtin(current->cmd_struct.cmd[0]))
			*current->cmd_struct.cmd = get_cmd_path(*current->cmd_struct.cmd);
		current = current->next;
	}
	if (!check_syntax(line))
		return (ft_error("minishell: syntax error\n", 258),
			parse_free(*lexer_head), 0);
	return (1);
}
