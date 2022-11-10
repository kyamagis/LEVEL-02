/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_less_than_6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 15:59:17 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/02 21:18:43 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	quantity_is_3(t_stack_list **a_lst, int64_t n)
{
	if ((*a_lst)->num == 0 + n && (*a_lst)->next->num == 2 + n)
		sa(a_lst);
	if ((*a_lst)->num == 2 + n && (*a_lst)->next->num == 1 + n)
		sa(a_lst);
	if ((*a_lst)->num == 1 + n && (*a_lst)->next->num == 2 + n)
		rra(a_lst);
	else if ((*a_lst)->num == 1 + n && (*a_lst)->next->num == 0 + n)
		sa(a_lst);
	else if ((*a_lst)->num == 2 + n && (*a_lst)->next->num == 0 + n)
		ra(a_lst);
}

static void	quantity_is_4(t_stack_list **a_lst, t_stack_list **b_lst)
{
	while (1)
	{
		if ((*a_lst)->num == 0)
			pb(a_lst, b_lst);
		if ((*a_lst)->num == NIL)
			break ;
		ra(a_lst);
	}
	*a_lst = (*a_lst)->next;
	quantity_is_3(a_lst, 1);
	pa(b_lst, a_lst);
}

static void	quantity_is_5(t_stack_list **a_lst, t_stack_list **b_lst)
{
	while (1)
	{
		while ((*a_lst)->num == 0 || (*a_lst)->num == 1)
			pb(a_lst, b_lst);
		if ((*a_lst)->num == NIL)
			break ;
		ra(a_lst);
	}
	*a_lst = (*a_lst)->next;
	quantity_is_3(a_lst, 2);
	pa(b_lst, a_lst);
	pa(b_lst, a_lst);
	if ((*a_lst)->num == 1)
		sa(a_lst);
}

void	arg_less_than_6(t_stack_list *a_lst, \
						t_stack_list *b_lst, size_t quantity)
{
	if (5 < quantity)
		return ;
	if (quantity == 2)
		sa(&a_lst);
	else if (quantity == 3)
		quantity_is_3(&a_lst, 0);
	else if (quantity == 4)
		quantity_is_4(&a_lst, &b_lst);
	else if (quantity == 5)
		quantity_is_5(&a_lst, &b_lst);
	exit(0);
}
