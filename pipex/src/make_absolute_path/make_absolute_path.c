/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_absolute_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:30:24 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:10:49 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static size_t	find_position_of_path(char **envp)
{
	size_t	i;

	i = 0;
	while (envp[i] && !ft_strnstr(envp[i], "PATH=", ft_strlen("PATH=") + 1))
		i++;
	if (envp[i] == NULL)
		ft_exit(NOT_FOUND_PATH);
	return (i);
}

static void	add_slash_command_to_paths_tail(char **absolute_paths, \
											char *command)
{
	size_t	i;
	char	*tmp;
	char	*slash_command;

	slash_command = ft_strjoin("/", command);
	i = 0;
	while (absolute_paths[i])
	{
		tmp = absolute_paths[i];
		absolute_paths[i] = ft_strjoin(absolute_paths[i], slash_command);
		free(tmp);
		i++;
	}
	free(slash_command);
}

static char	*search_accessible_absolute_path(char **absolute_paths, \
											char *command)
{
	size_t	i;

	i = 0;
	while (absolute_paths[i] && access(absolute_paths[i], X_OK))
		i++;
	if (absolute_paths[i] != NULL)
		return (ft_strdup(absolute_paths[i]));
	i = 0;
	while (absolute_paths[i] && access(absolute_paths[i], F_OK))
		i++;
	if (absolute_paths[i] != NULL)
		strerror_exit(EACCES, absolute_paths[i]);
	message_exit(COMMAND_NOT_FOUND, command);
	return (NULL);
}		

void	make_absolute_path(char **envp, char *cmd)
{
	size_t	position_of_path;
	char	**absolute_paths;
	char	*a_path_command;
	char	**cmd_and_options;

	if (cmd[0] == '\0')
		message_exit(COMMAND_NOT_FOUND, cmd);
	cmd_and_options = split_space_and_quote(cmd);
	if_slash_exists_cmd(envp, cmd_and_options);
	position_of_path = find_position_of_path(envp);
	absolute_paths = ft_split(&envp[position_of_path][ft_strlen("PATH=")], ':');
	add_slash_command_to_paths_tail(absolute_paths, cmd_and_options[0]);
	a_path_command = search_accessible_absolute_path(absolute_paths, \
													cmd_and_options[0]);
	execve(a_path_command, cmd_and_options, envp);
	ft_exit(EXECVE_FAILURE);
}

/*__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q a.out");
}

int	main(int argc, char **argv, char **envp)
{
	
	make_absolute_path(envp, "ls -l");
}*/