/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybel-hac <ybel-hac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:11:31 by bahbibe           #+#    #+#             */
/*   Updated: 2023/03/09 09:35:57 by ybel-hac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_prompt(char *limit, int fd[2], int flag)
{
	char	*line;
	char	*temp;

	line = readline("> ");
	if (!line)
		exit(EXIT_SUCCESS);
	if (ft_strcmp(line, limit))
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	if (!flag)
		ft_putstr(line, fd[1]);
	else if (ft_strlen(line))
	{
		temp = smart_get_variable(line, 1);
		ft_putstr(temp, fd[1]);
		free(temp);
	}
	ft_putstr("\n", fd[1]);
	free(line);
}

void	get_file_fd(int *files, int *fd_io)
{
	if (files[0] != -1)
		fd_io[0] = files[0];
	if (files[1] != -1)
		fd_io[1] = files[1];
}

int	*dup_files(t_lexer_node *head, int pip[2], int tmp, int flag)
{
	int	fd_io[2];
	int	*files;

	files = open_files(head);
	if (!files)
		return (0);
	fd_io[1] = pip[1];
	fd_io[0] = 0;
	if (flag == FIRST)
		get_file_fd(files, fd_io);
	else if (flag == INPIPE)
	{
		fd_io[0] = tmp;
		get_file_fd(files, fd_io);
	}
	else if (flag == LAST || flag == SINGLE)
	{
		fd_io[1] = 1;
		if (flag == LAST)
			fd_io[0] = tmp;
		get_file_fd(files, fd_io);
	}
	dup2(fd_io[1], 1);
	return (dup2(fd_io[0], 0), files);
}

int	open_herdoc(char *limit, int flag)
{
	int		fd[2];
	int		pid;
	int		status;

	pipe(fd);
	pid = fork();
	if (!pid)
	{
		signal(SIGINT, sig_heredoc);
		while (1)
			heredoc_prompt(limit, fd, flag);
	}
	else
		wait(&status);
	g_global.error = exit_stat(status);
	if (g_global.error)
	{
		printf("\n");
		g_global.open_heredoc = 1;
	}
	return (close(fd[1]), fd[0]);
}

int	open_file(char *file, char flag)
{
	int	fd;

	if (flag == 'A')
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (flag == 'O')
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else
		fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		if (g_global.inparent == 1)
			exit(EXIT_FAILURE);
		else
			fd = -2;
	}
	return (fd);
}
