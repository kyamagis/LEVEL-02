/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_core_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:09:24 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 19:25:14 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	fork_and_cmd_execution(t_shell shell, \
									int *pipefd, int first_or_secound)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(FORK_FAILURE);
	else if (pid == CHILD_PROCESS)
	{	
		if (first_or_secound == FIRST_FORK)
			call_multiple_pipes_func(shell, \
								shell.argc, \
								pipefd, \
								shell.pipe_count);
		else if (first_or_secound == SECOUND_FORK)
			final_cmd_process(shell, pipefd);
	}
}

void	pipex_core(t_shell shell)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit(PIPE_FAILURE);
	fork_and_cmd_execution(shell, pipefd, FIRST_FORK);
	fork_and_cmd_execution(shell, pipefd, SECOUND_FORK);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
	wait_error_and_exit_failure_is_exit(shell);
}
