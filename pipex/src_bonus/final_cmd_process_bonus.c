/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_cmd_process_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:09:07 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 19:25:15 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	final_cmd_process(t_shell shell, int *pipefd)
{
	int	outfile_fd;

	outfile_fd = 0;
	if (shell.re_or_here == REDIRECTON)
		outfile_fd = open(shell.argv[shell.argc - 1], \
						O_CREAT | O_WRONLY | O_TRUNC, ONLY_WRITE_PERMISSION);
	else
		outfile_fd = open(shell.argv[shell.argc - 1], \
						O_CREAT | O_WRONLY | O_APPEND, ONLY_WRITE_PERMISSION);
	if (outfile_fd == -1)
		ft_exit(OPEN_FAILURE);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(outfile_fd);
	close(pipefd[WRITE]);
	if (dup2(pipefd[READ], STDIN_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(pipefd[READ]);
	make_absolute_path(shell.envp, \
						shell.argv[shell.argc - 2]);
}
