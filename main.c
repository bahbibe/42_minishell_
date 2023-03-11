/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:44:17 by bahbibe           #+#    #+#             */
/*   Updated: 2023/03/08 22:44:14 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minishell.h"

void	minishell(char *line, char **env)
{
	char			**args;
	int				i;
	t_lexer_node	*head;

	head = 0;
	i = -1;
	args = ft_split_costom(line);
	while (args[++i])
		if (!check_quotes(args[i]))
			return (tab_free(args));
	i = -1;
	while (args[++i])
		init_lexer_node(&head, args[i], env);
	free(args);
	if (parser_utils(&head, line))
	{
		g_global.head = head;
		executor(head);
		free_parser(head);
		lst_clear(&head);
	}
}

void	close_saved_fd(int *files)
{
	close(files[0]);
	close(files[1]);
	free(files);
}

int	main(int ac, char **av, char **env)
{
	char			*line;

	init_var(ac, av, env);
	while (1)
	{
		g_global.open_heredoc = 0;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sig_handler);
		line = readline("\e[1;32mminishell~> \e[0m");
		signal(SIGINT, SIG_IGN);
		if (!line)
			return (printf("exit\n"), g_global.error);
		g_global.save = save_();
		if (ft_strlen(line) && check_empty(line))
		{
			add_history(line);
			minishell(line, env);
			reset_io(g_global.save);
		}
		close_saved_fd(g_global.save);
		free(line);
	}
	return (0);
}
