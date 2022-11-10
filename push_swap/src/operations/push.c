/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:28:14 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/03 10:48:09 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack_list	**a_lst, t_stack_list **b_lst)
{
	t_stack_list	*tmp_a_lst;
	t_stack_list	*a_lst_prev;
	t_stack_list	*b_lst_prev;

	tmp_a_lst = *a_lst;
	a_lst_prev = (*a_lst)->prev;
	*a_lst = (*a_lst)->next;
	a_lst_prev->next = *a_lst;
	(*a_lst)->prev = a_lst_prev;
	b_lst_prev = (*b_lst)->prev;
	(*b_lst)->prev = tmp_a_lst;
	tmp_a_lst->next = *b_lst;
	b_lst_prev->next = tmp_a_lst;
	tmp_a_lst->prev = b_lst_prev;
	*b_lst = (*b_lst)->prev;
	ft_printf("pb\n");
}

void	pa(t_stack_list	**a_lst, t_stack_list **b_lst)
{
	t_stack_list	*tmp_a_lst;
	t_stack_list	*a_lst_prev;
	t_stack_list	*b_lst_prev;

	tmp_a_lst = *a_lst;
	a_lst_prev = (*a_lst)->prev;
	*a_lst = (*a_lst)->next;
	a_lst_prev->next = *a_lst;
	(*a_lst)->prev = a_lst_prev;
	b_lst_prev = (*b_lst)->prev;
	(*b_lst)->prev = tmp_a_lst;
	tmp_a_lst->next = *b_lst;
	b_lst_prev->next = tmp_a_lst;
	tmp_a_lst->prev = b_lst_prev;
	*b_lst = (*b_lst)->prev;
	ft_printf("pa\n");
}
