/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:00:45 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:10:35 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	discriminate_accessible_file(char *infile_name, char *outfile_name)
{
	if (access(infile_name, R_OK) == ACCESSIBLE)
	{
		if (access(outfile_name, W_OK) == ACCESSIBLE)
			return ;
		if (access(outfile_name, F_OK) == ACCESSIBLE)
			strerror_exit(EACCES, outfile_name);
		else
			return ;
	}
	if (access(infile_name, F_OK) == ACCESSIBLE)
		strerror_exit(EACCES, infile_name);
	else
		strerror_exit(ENOENT, infile_name);
}

static void	fork_and_cmd_execution(int	*pipefd, char **argv, \
								char **envp, int first_or_secound)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(FORK_FAILURE);
	else if (pid == CHILD_PROCESS)
	{	
		if (first_or_secound == FIRST_FORK)
			child_process_for_cmd1(pipefd, argv, envp);
		else if (first_or_secound == SECOUND_FORK)
			child_process_for_cmd2(pipefd, argv, envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];

	if (argc != 5)
		ft_exit(USAGE);
	discriminate_accessible_file(argv[INFILE], argv[OUTFILE]);
	if (pipe(pipefd) == -1)
		ft_exit(PIPE_FAILURE);
	fork_and_cmd_execution(pipefd, argv, envp, FIRST_FORK);
	fork_and_cmd_execution(pipefd, argv, envp, SECOUND_FORK);
	close(pipefd[READ]);
	close(pipefd[WRITE]);
	wait_error_and_exit_failure_is_exit();
	return (0);
}

/*
printf("%s, %s\n", argv[1], argv[2]);

__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q pipex");
}

void	print_double_pointer(char **envp)
{
	size_t	i = 0;

	while(envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}
}*/
