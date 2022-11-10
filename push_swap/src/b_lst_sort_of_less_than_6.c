/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_lst_sort_of_less_than_6.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 14:20:08 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/02 21:29:26 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_of_2(t_stack_list **a_lst, t_stack_list **b_lst)
{
	if ((*b_lst)->num < (*b_lst)->next->num)
	{
		(*b_lst)->group = SORTED;
		pa(b_lst, a_lst);
		ra(a_lst);
		(*b_lst)->group = SORTED;
		pa(b_lst, a_lst);
		ra(a_lst);
		return ;
	}
	(*b_lst)->group = SORTED;
	pa(b_lst, a_lst);
	(*b_lst)->group = SORTED;
	pa(b_lst, a_lst);
	ra(a_lst);
	ra(a_lst);
}

static void	sort_of_3(t_stack_list **a_lst, t_stack_list **b_lst)
{
	if ((*b_lst)->num != find_min(*b_lst) && (*b_lst)->num != find_max(*b_lst))
		sb(b_lst);
	if ((*b_lst)->num == find_min(*b_lst))
	{
		(*b_lst)->group = SORTED;
		pa(b_lst, a_lst);
		ra(a_lst);
		sort_of_2(a_lst, b_lst);
	}
	else if ((*b_lst)->num == find_max(*b_lst))
	{
		(*b_lst)->group = SORTED;
		pa(b_lst, a_lst);
		sort_of_2(a_lst, b_lst);
		ra(a_lst);
	}
}

static void	sort_of_4(t_stack_list **a_lst, t_stack_list **b_lst)
{
	int64_t	max;
	int64_t	sub_max;

	max = find_max(*b_lst);
	sub_max = max - 1;
	while (1)
	{
		while ((*b_lst)->num == max || (*b_lst)->num == sub_max)
		{
			(*b_lst)->group = SORTED;
			pa(b_lst, a_lst);
		}
		if ((*b_lst)->num == NIL)
			break ;
		rb(b_lst);
	}
	*b_lst = (*b_lst)->next;
	if ((*a_lst)->next->num < (*a_lst)->num)
		sa(a_lst);
	sort_of_2(a_lst, b_lst);
	ra(a_lst);
	ra(a_lst);
}

static void	sort_of_5(t_stack_list **a_lst, t_stack_list **b_lst)
{
	int64_t	max;
	int64_t	sub_max;

	max = find_max(*b_lst);
	sub_max = max - 1;
	while (1)
	{
		while ((*b_lst)->num == max || (*b_lst)->num == sub_max)
		{
			(*b_lst)->group = SORTED;
			pa(b_lst, a_lst);
		}
		if ((*b_lst)->num == NIL)
			break ;
		rb(b_lst);
	}
	*b_lst = (*b_lst)->next;
	if ((*a_lst)->next->num < (*a_lst)->num)
		sa(a_lst);
	sort_of_3(a_lst, b_lst);
	ra(a_lst);
	ra(a_lst);
}

void	b_lst_sort_of_less_than_6(t_stack_list **a_lst, \
							t_stack_list **b_lst, int64_t structs_quantity)
{
	if (structs_quantity == 1)
	{
		(*b_lst)->group = SORTED;
		pa(b_lst, a_lst);
		ra(a_lst);
	}
	else if (structs_quantity == 2)
		sort_of_2(a_lst, b_lst);
	else if (structs_quantity == 3)
		sort_of_3(a_lst, b_lst);
	else if (structs_quantity == 4)
		sort_of_4(a_lst, b_lst);
	else if (structs_quantity == 5)
		sort_of_5(a_lst, b_lst);
}	
