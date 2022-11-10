/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space_and_quote_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:05:06 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:14:51 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

static t_str_list	*splited_quotation(char const *s)
{
	t_str_list	*strsplit;

	if (s == NULL)
		return (NULL);
	strsplit = (t_str_list *)malloc(sizeof(t_str_list));
	if (strsplit == NULL)
		ft_exit(MALLOC_FAILURE);
	strsplit->next = NULL;
	return (ft_strsplit(strsplit, s));
}

int	search_non_specified_chr(const char *s, int c)
{
	size_t			i;
	unsigned char	*suc;
	unsigned char	cuc;

	suc = (unsigned char *)s;
	cuc = (unsigned char)c;
	i = 0;
	while (suc[i] != '\0')
	{
		if (suc[i] != cuc)
			return (FOUND);
		i++;
	}
	return (NOT_FOUND);
}

static char	**copy_to_double_pointer(t_str_list *str_list, size_t str_count)
{
	size_t		i;
	char		**joined_str;
	t_str_list	*tmp_list;

	joined_str = (char **)malloc(sizeof(char *) * (str_count + 1));
	if (joined_str == NULL)
		ft_exit(MALLOC_FAILURE);
	i = 0;
	while (str_list)
	{
		joined_str[i] = str_list->str;
		tmp_list = str_list;
		str_list = str_list->next;
		free(tmp_list);
		i++;
	}
	joined_str[i] = NULL;
	return (joined_str);
}

char	**split_space_and_quote(char *cmd)
{
	t_str_list	*str_list;
	t_str_list	*strsplit;
	size_t		str_count;
	char		**joined_str;

	if (cmd == NULL)
		return (NULL);
	if (cmd[0] == '\0')
		return (NULL);
	str_list = (t_str_list *)malloc(sizeof(t_str_list));
	if (str_list == NULL)
		ft_exit(MALLOC_FAILURE);
	strsplit = splited_quotation(cmd);
	str_count = skip_space_and_join_str(str_list, strsplit);
	joined_str = copy_to_double_pointer(str_list, str_count);
	return (joined_str);
}

/*
int main (int argc, char **argv)
{
	if (argc != 2)
		return (0);
	printf("argv = %s\n\n", argv[1]);
	t_str_list *list = splited_quotation(argv[1]);
	

	t_str_list *tmp = list;
	size_t	i = 0;
	while (tmp)
	{
		printf("%ld, +%s+\n", i++, tmp->str);
		tmp = tmp->next;
	}


	char **str = if_quart_exists(argv[1]);
	size_t i = 0;
	while (str && str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	exit(0);
	

}
*/