/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_multiple_pipes_func_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:11:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:15:58 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	middle_cmd_process(int *pipefd, char *cmd, char **envp)
{
	close(pipefd[WRITE]);
	if (dup2(pipefd[READ], STDIN_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(pipefd[READ]);
	make_absolute_path(envp, cmd);
}

static void	multiple_pipes(t_shell shell, \
							int argc, size_t pipe_count)
{
	int		pipefd[2];
	pid_t	pid;

	if (argc == 5 + shell.re_or_here)
		first_cmd_line_list_process(shell, pipe_count);
	if (pipe(pipefd) == -1)
		ft_exit(PIPE_FAILURE);
	pid = fork();
	if (pid == -1)
		ft_exit(FORK_FAILURE);
	else if (pid == CHILD_PROCESS)
		call_multiple_pipes_func(shell, argc - 1, \
								pipefd, pipe_count + 1);
	else
		middle_cmd_process(pipefd, shell.argv[argc - 3], \
							shell.envp);
}

void	call_multiple_pipes_func(t_shell shell, \
									int argc, \
									int *pipefd, \
									size_t pipe_count)
{
	close(pipefd[READ]);
	if (dup2(pipefd[WRITE], STDOUT_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(pipefd[WRITE]);
	multiple_pipes(shell, argc, pipe_count);
}
