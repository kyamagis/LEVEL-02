/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:11:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/30 20:07:03 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_process_for_cmd1(int *pipefd, char **argv, char **envp)
{
	int	infile_fd;

	close(pipefd[READ]);
	infile_fd = open(argv[INFILE], O_RDONLY);
	if (infile_fd == -1)
		ft_exit(OPEN_FAILURE);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(infile_fd);
	if (dup2(pipefd[WRITE], STDOUT_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(pipefd[WRITE]);
	make_absolute_path(envp, argv[2]);
}

void	child_process_for_cmd2(int *pipefd, char **argv, char **envp)
{
	int	outfile_fd;

	close(pipefd[WRITE]);
	outfile_fd = open(argv[OUTFILE], O_CREAT | O_WRONLY | O_TRUNC, \
				ONLY_WRITE_PERMISSION);
	if (outfile_fd == -1)
		ft_exit(OPEN_FAILURE);
	if (dup2(outfile_fd, STDOUT_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(outfile_fd);
	if (dup2(pipefd[READ], STDIN_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(pipefd[READ]);
	make_absolute_path(envp, argv[3]);
}
