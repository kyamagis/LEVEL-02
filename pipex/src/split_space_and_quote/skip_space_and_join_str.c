/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_space_and_join_str.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:04:11 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:13:33 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	strjoin_not_only_space(t_str_list *str_list, t_str_list **strsplit)
{
	char		*tmp_str;
	t_str_list	*tmp_list;

	str_list->str = NULL;
	while ((*strsplit) && (*strsplit)->quote_flg == FOUND)
	{
		tmp_str = ft_strjoin(str_list->str, (*strsplit)->str);
		free(str_list->str);
		free((*strsplit)->str);
		tmp_list = (*strsplit);
		str_list->str = tmp_str;
		(*strsplit) = (*strsplit)->next;
		free(tmp_list);
	}
}

static void	skip_only_space_str_and_free(t_str_list **strsplit)
{
	t_str_list	*tmp;

	while ((*strsplit) && (*strsplit)->quote_flg == NOT_FOUND)
	{
		tmp = (*strsplit);
		free((*strsplit)->str);
		(*strsplit) = (*strsplit)->next;
		free(tmp);
	}
}

size_t	skip_space_and_join_str(t_str_list *str_list, t_str_list *strsplit)
{
	size_t		str_count;
	t_str_list	*tmp;

	str_list->next = NULL;
	tmp = str_list;
	str_count = 1;
	while (1)
	{
		skip_only_space_str_and_free(&strsplit);
		strjoin_not_only_space(tmp, &strsplit);
		if (!strsplit)
			break ;
		join_structure(&tmp);
		str_count++;
	}
	free(strsplit);
	return (str_count);
}
