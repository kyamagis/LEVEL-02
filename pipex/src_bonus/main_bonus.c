/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 21:00:45 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 19:25:14 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

static int	check_whether_argv_1_is_here_doc(int argc, char **argv)
{
	if (ft_strncmp("here_doc", \
		argv[1], ft_strlen("here_doc") + 1) == HERE_D && 5 < argc)
	{
		if (access(argv[argc - 1], W_OK) == ACCESSIBLE)
			return (HERE_DOC);
		if (access(argv[argc - 1], F_OK) == ACCESSIBLE)
			strerror_exit(EACCES, argv[argc - 1]);
		return (HERE_DOC);
	}
	else
	{
		discriminate_accessible_file(argv[1], argv[argc - 1]);
		return (REDIRECTON);
	}
}

static void	shell_init(t_shell *shell, \
								int argc, char **argv, char **envp)
{
	shell->re_or_here = \
					check_whether_argv_1_is_here_doc(argc, argv);
	shell->argc = argc;
	shell->argv = argv;
	shell->envp = envp;
	shell->pipe_count = 1;
	shell->file_name = NULL;
	if (shell->re_or_here == HERE_DOC)
		shell->file_name = create_unique_file_name("here_doc");
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	if (argc < 5)
		ft_exit(USAGE);
	check_whether_argv_1_is_here_doc(argc, argv);
	shell_init(&shell, argc, argv, envp);
	pipex_core(shell);
	delete_created_file(shell);
	exit(EXIT_SUCCESS);
	return (0);
}

/*


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
