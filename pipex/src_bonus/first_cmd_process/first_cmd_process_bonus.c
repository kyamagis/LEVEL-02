/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_cmd_line_list_process_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:09:14 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 19:25:16 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	redirection_process(t_shell shell)
{
	int	infile_fd;

	infile_fd = open(shell.argv[1], O_RDONLY);
	if (infile_fd == -1)
		ft_exit(OPEN_FAILURE);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(infile_fd);
	make_absolute_path(shell.envp, shell.argv[2]);
}

void	first_cmd_line_list_process(t_shell shell, size_t pipes_count)
{
	if (shell.re_or_here == REDIRECTON)
		redirection_process(shell);
	else if (shell.re_or_here == HERE_DOC)
		here_doc_process(shell, pipes_count);
}
