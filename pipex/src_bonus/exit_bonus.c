/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:08:47 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:19:16 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	strerror_exit(int error_plus_flg, char *file_name)
{
	ft_putstr_fd(strerror(error_plus_flg), STDERR_FILENO);
	write(STDERR_FILENO, ": ", STDERR_FILENO);
	ft_putendl_fd(file_name, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	message_exit(char *message, char *command)
{
	ft_putstr_fd(message, STDERR_FILENO);
	write(STDERR_FILENO, ": ", STDERR_FILENO);
	ft_putendl_fd(command, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_exit(char *error_plus_flg)
{
	ft_putendl_fd(error_plus_flg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	delete_created_file(t_shell	shell)
{
	if (shell.re_or_here == REDIRECTON)
		return ;
	if (unlink(shell.file_name) == -1)
		ft_exit(UNLIMK_FAILURE);
}

void	wait_error_and_exit_failure_is_exit(t_shell	shell)
{
	int	status;

	if (wait(&status) == -1)
	{
		delete_created_file(shell);
		ft_exit(WAITPID_FAILURE);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status))
	{	
		delete_created_file(shell);
		exit(EXIT_FAILURE);
	}
	if (wait(&status) == -1)
	{
		delete_created_file(shell);
		ft_exit(WAITPID_FAILURE);
	}
	if (WIFEXITED(status) && WEXITSTATUS(status))
	{
		delete_created_file(shell);
		exit(EXIT_FAILURE);
	}
}
