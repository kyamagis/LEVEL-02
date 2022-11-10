/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_absolute_path_1_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 17:30:24 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/31 15:31:43 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	if_slash_exists_cmd(char **envp, char **cmd_and_options)
{
	if (ft_strchr(cmd_and_options[0], '/') == NULL)
		return ;
	if (access(cmd_and_options[0], X_OK) == ACCESSIBLE)
	{	
		execve(cmd_and_options[0], cmd_and_options, envp);
		ft_exit(EXECVE_FAILURE);
	}
	if (access(cmd_and_options[0], F_OK) == ACCESSIBLE)
		strerror_exit(EACCES, cmd_and_options[0]);
	else
		strerror_exit(ENOENT, cmd_and_options[0]);
}
