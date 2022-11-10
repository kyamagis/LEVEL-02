/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_lst_group_quantity_less_than_6.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:54:22 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/02 21:26:06 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	a_lst_head_num_is_min(t_stack_list **a_lst)
{
	(*a_lst)->group = SORTED;
	ra(a_lst);
	if ((*a_lst)->next->num < (*a_lst)->num)
		sa(a_lst);
	(*a_lst)->group = SORTED;
	ra(a_lst);
	(*a_lst)->group = SORTED;
	ra(a_lst);
}

static void	a_lst_head_num_is_max(t_stack_list **a_lst, t_stack_list **b_lst)
{
	(*a_lst)->group = SORTED;
	pb(a_lst, b_lst);
	if ((*a_lst)->next->num < (*a_lst)->num)
		sa(a_lst);
	(*a_lst)->group = SORTED;
	ra(a_lst);
	(*a_lst)->group = SORTED;
	ra(a_lst);
	pa(b_lst, a_lst);
	ra(a_lst);
}

static void	a_lst_head_num_is_middle(t_stack_list **a_lst, t_stack_list **b_lst)
{
	(*a_lst)->group = SORTED;
	pb(a_lst, b_lst);
	if ((*a_lst)->next->num < (*a_lst)->num)
		sa(a_lst);
	(*a_lst)->group = SORTED;
	ra(a_lst);
	pa(b_lst, a_lst);
	ra(a_lst);
	(*a_lst)->group = SORTED;
	ra(a_lst);
}

void	a_lst_group_quantity_less_than_6(t_stack_list **a_lst, \
											t_stack_list **b_lst, \
											size_t group_quantity)
{
	if (group_quantity == 1)
	{
		(*a_lst)->group = SORTED;
		ra(a_lst);
	}
	if (group_quantity == 2)
	{
		if ((*a_lst)->next->num < (*a_lst)->num)
			sa(a_lst);
		(*a_lst)->group = SORTED;
		ra(a_lst);
		(*a_lst)->group = SORTED;
		ra(a_lst);
	}
	if (group_quantity == 3)
	{
		if ((*a_lst)->num == find_min(*a_lst))
			a_lst_head_num_is_min(a_lst);
		else if ((*a_lst)->num == find_max(*a_lst))
			a_lst_head_num_is_max(a_lst, b_lst);
		else
			a_lst_head_num_is_middle(a_lst, b_lst);
	}
}
