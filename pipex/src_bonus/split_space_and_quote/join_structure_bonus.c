/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_structure_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:04:56 by kyamagis          #+#    #+#             */
/*   Updated: 2022/09/07 12:04:58 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/pipex_bonus.h"

void	join_structure(t_str_list **str_list)
{
	t_str_list	*tmp;

	tmp = (t_str_list *)malloc(sizeof(t_str_list));
	if (tmp == NULL)
		ft_exit(MALLOC_FAILURE);
	(*str_list)->next = tmp;
	(*str_list) = (*str_list)->next;
	(*str_list)->next = NULL;
}
