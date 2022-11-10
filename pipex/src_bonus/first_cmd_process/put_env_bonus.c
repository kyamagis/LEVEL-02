/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_envp_list_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:04:42 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:20:34 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static size_t	put_str(char *search_str, \
						char **envp, int infile_fd, size_t len)
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], search_str, ft_strlen(search_str)) == 0)
		{
			ft_putstr_fd(&envp[i][ft_strlen(search_str)], infile_fd);
			free(search_str);
			return (len + 1);
		}
		i++;
	}
	free(search_str);
	return (len + 1);
}

static size_t	search_str_from_envp(char *str, char **envp, int infile_fd)
{
	size_t	len;
	char	*sub_str;
	char	*search_str;

	len = 0;
	while (str[len] && str[len] != '\n' && str[len] != ' ')
		len++;
	sub_str = ft_substr(str, 0, len);
	search_str = ft_strjoin(sub_str, "=");
	free(sub_str);
	return (put_str(search_str, envp, infile_fd, len));
}

void	put_envp_list(char *str, char **envp, int infile_fd)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			i += search_str_from_envp(&str[i + 1], envp, infile_fd);
		ft_putchar_fd(str[i], infile_fd);
		i++;
	}
}

/*int main(int argc, char **argv, char **envp)
{
	if (argc != 1)
		return (0);
	printf("%s\n", argv[0]);
	put_envp_list("1111111$PATH a\n", envp, STDOUT_FILENO);
	put_envp_list("1111111$PATH222222\n", envp, STDOUT_FILENO);
	put_envp_list("$PAT \n\n", envp, STDOUT_FILENO);
	printf("\n");
	exit(0);
}
*/