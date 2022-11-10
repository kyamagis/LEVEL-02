/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:03:57 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:12:26 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex.h"

static void	dup_double_quote_str(size_t	*i, \
								char const *str, \
								t_str_list *strsplit)
{
	size_t	str_len;
	size_t	start_idx;

	(*i)++;
	start_idx = *i;
	str_len = 0;
	while (str[*i] && str[*i] != '\"')
	{
		str_len++;
		(*i)++;
	}
	if (str[*i] == '\0')
		ft_exit("only a quotation");
	if (str[*i] == '\"')
		(*i)++;
	strsplit->str = ft_substr(str, start_idx, str_len);
	strsplit->quote_flg = FOUND;
}

static void	dup_single_quote_str(size_t	*i, \
								char const *str, \
								t_str_list *strsplit)
{
	size_t	str_len;
	size_t	start_idx;

	(*i)++;
	start_idx = *i;
	str_len = 0;
	while (str[*i] && str[*i] != '\'')
	{
		str_len++;
		(*i)++;
	}
	if (str[*i] == '\0')
		ft_exit("only a quotation");
	if (str[*i] == '\'')
		(*i)++;
	strsplit->str = ft_substr(str, start_idx, str_len);
	strsplit->quote_flg = FOUND;
}

static void	dup_space(size_t *i, char const *str, t_str_list *strsplit)
{
	size_t	str_len;

	(*i)++;
	str_len = 0;
	while (str[*i] && str[*i] == ' ')
	{
		str_len++;
		(*i)++;
	}
	if (str[*i] == '\0')
	{	
		strsplit->str = ft_strdup("");
		strsplit->next = NULL;
	}
	else
		strsplit->str = ft_strdup(" ");
	strsplit->quote_flg = NOT_FOUND;
}

static void	dup_else_str(size_t	*i, char const *str, t_str_list *strsplit)
{
	size_t	str_len;
	size_t	start_idx;

	start_idx = *i;
	str_len = 0;
	while (str[*i] && str[*i] != '\"' && str[*i] != '\'' && str[*i] != ' ')
	{
		str_len++;
		(*i)++;
	}
	strsplit->str = ft_substr(str, start_idx, str_len);
	strsplit->quote_flg = FOUND;
}

t_str_list	*ft_strsplit(t_str_list *strsplit, char const *str)
{
	size_t		i;
	t_str_list	*tmp;

	tmp = strsplit;
	i = 0;
	while (42)
	{
		if (str[i] && str[i] == '\"')
			dup_double_quote_str(&i, str, tmp);
		else if (str[i] && str[i] == '\'')
			dup_single_quote_str(&i, str, tmp);
		else if (str[i] && str[i] == ' ')
			dup_space(&i, str, tmp);
		else
			dup_else_str(&i, str, tmp);
		if (!str[i])
			break ;
		join_structure(&tmp);
	}
	return (strsplit);
}
