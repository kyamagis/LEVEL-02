/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_process_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:04:36 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:18:31 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static void	put_here_doc_arrow(size_t pipes_count)
{
	size_t	i;

	i = 0;
	while (i < pipes_count)
	{
		ft_putstr_fd("pipe ", STDIN_FILENO);
		i++;
	}
	ft_putstr_fd("heredoc> ", STDIN_FILENO);
}

static int	search_slash_and_quotation(char *str)
{
	if (ft_strchr(str, '\"') != NULL)
		return (FOUND);
	if (ft_strchr(str, '\'') != NULL)
		return (FOUND);
	if (str[0] == '\\')
		return (FOUND);
	return (NOT_FOUND);
}

static void	write_to_infile(t_shell shell, \
			size_t pipes_count, int infile_fd, int found_flg)
{
	char	*str;

	while (1)
	{
		put_here_doc_arrow(pipes_count);
		str = get_next_line(STDIN_FILENO);
		if (str == NULL)
			break ;
		if (!ft_strncmp(str, shell.argv[2], \
			ft_strlen(shell.argv[2])) && \
			str[ft_strlen(shell.argv[2])] == '\n')
			break ;
		if (found_flg == NOT_FOUND)
			put_envp_list(str, shell.envp, infile_fd);
		else
			ft_putstr_fd(str, infile_fd);
		free(str);
	}
	free(str);
}

static void	create_infile_and_write(t_shell shell, \
							size_t pipes_count)
{
	int	infile_fd;
	int	found_flg;

	infile_fd = open(shell.file_name, O_CREAT | O_RDWR | O_TRUNC, \
					ONLY_WRITE_PERMISSION);
	if (infile_fd == -1)
		ft_exit(OPEN_FAILURE);
	found_flg = search_slash_and_quotation(shell.argv[2]);
	write_to_infile(shell, pipes_count, infile_fd, found_flg);
	close(infile_fd);
}

void	here_doc_process(t_shell shell, \
							size_t pipes_count)
{
	int	infile_fd;

	create_infile_and_write(shell, pipes_count);
	infile_fd = open(shell.argv[1], O_RDONLY);
	if (infile_fd == -1)
		ft_exit(OPEN_FAILURE);
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		ft_exit(DUP2_ERROR);
	close(infile_fd);
	make_absolute_path(shell.envp, shell.argv[3]);
}
