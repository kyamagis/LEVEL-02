/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/11/10 17:41:57 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define OPEN_FAILURE "open failure"
# define WAITPID_FAILURE "Waitpid failure"
# define MALLOC_FAILURE "Malloc failure"
# define PIPE_FAILURE "Pipe failure"
# define FORK_FAILURE "Fork failure"
# define EXECVE_FAILURE "Execve failure"
# define USAGE "usage   : ./pipex infile \"cmd1\" \"cmd2\" outfile\n\
example : ./pipex infile \"ls -l\" \"wc -l\" outfile\n\
        : ./pipex infile \"cat -n\" \"cat\" outfile"
# define NOT_FOUND_PATH "Not found PATH form envp"
# define COMMAND_NOT_FOUND "Command not found"
# define DUP2_ERROR "dup2 error"
# define ONLY_WRITE_PERMISSION 0644
# define READ 0
# define WRITE 1
# define CHILD_PROCESS 0
# define ACCESSIBLE 0
# define NOT_ACCESS -1
# define FOUND 0
# define NOT_FOUND 1
# define INFILE 1
# define OUTFILE 4
# define FIRST_FORK 0
# define SECOUND_FORK 1

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_str_list
{
	char				*str;
	int					quote_flg;
	struct s_str_list	*next;
}	t_str_list;

void		wait_error_and_exit_failure_is_exit(void);
void		ft_exit(char *error_plus_flg);
void		message_exit(char *message, char *command);
void		strerror_exit(int error_plus_flg, char *file_name);
void		make_absolute_path(char **envp, char *cmd);
void		child_process_for_cmd1(int *pipefd, char **argv, char **envp);
void		child_process_for_cmd2(int *pipefd, char **argv, char **envp);
void		if_slash_exists_cmd(char **envp, char **cmd_and_options);

t_str_list	*ft_strsplit(t_str_list *strsplit, char const *str);
size_t		skip_space_and_join_str(t_str_list *str_list, t_str_list *strsplit);
void		join_structure(t_str_list **str_list);
char		**split_space_and_quote(char *cmd);

#endif
