/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 21:05:34 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/02 21:05:42 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int64_t	find_min(t_stack_list *lst)
{
	int64_t	min;
	int64_t	group;

	group = lst->group;
	min = lst->num;
	while (lst->num != NIL && group == lst->group)
	{
		if (lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	return (min);
}

int64_t	find_max(t_stack_list *lst)
{
	int64_t	max;
	int64_t	group;

	group = lst->group;
	max = lst->num;
	while (lst->num != NIL && group == lst->group)
	{
		if (max < lst->num)
			max = lst->num;
		lst = lst->next;
	}
	return (max);
}
