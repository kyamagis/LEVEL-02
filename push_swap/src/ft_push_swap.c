/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 18:33:10 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/02 21:27:10 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int64_t	calculate_pivot(t_stack_list *lst)
{
	int64_t			max;
	int64_t			min;
	int64_t			group;

	max = lst->num;
	min = lst->num;
	group = lst->group;
	while (lst->num != NIL || group == lst->group)
	{
		if (max < lst->num)
			max = lst->num;
		if (lst->num < min)
			min = lst->num;
		lst = lst->next;
	}
	return ((max + min) / 2);
}

static size_t	count_lst_struct(t_stack_list *lst)
{
	size_t	struct_counter;
	int64_t	group;

	group = lst->group;
	struct_counter = 0;
	while (lst->num != NIL && group == lst->group)
	{
		struct_counter++;
		lst = lst->next;
	}
	return (struct_counter);
}

static void	a_lst_ope(t_stack_list **a_lst, t_stack_list **b_lst)
{
	int64_t	group;
	int64_t	pivot;

	group = (*a_lst)->group;
	pivot = calculate_pivot(*a_lst);
	while (1)
	{
		while ((*a_lst)->num <= pivot && \
				(*a_lst)->num != NIL && group == (*a_lst)->group)
		{	
			(*a_lst)->group = pivot;
			pb(a_lst, b_lst);
		}
		if ((*a_lst)->num == NIL || group != (*a_lst)->group)
			break ;
		ra(a_lst);
	}
	if ((*a_lst)->num == NIL && (*a_lst)->next->group != SORTED)
		*a_lst = (*a_lst)->next;
	else
	{
		while ((*a_lst)->prev->group == group)
			rra(a_lst);
	}
}

static void	b_lst_ope(t_stack_list **a_lst, t_stack_list **b_lst)
{
	int64_t	pivot;

	while (5 < count_lst_struct(*b_lst))
	{
		pivot = calculate_pivot(*b_lst);
		while (1)
		{
			while (pivot < (*b_lst)->num && (*b_lst)->num != NIL)
			{	
				(*b_lst)->group = pivot;
				pa(b_lst, a_lst);
			}
			if ((*b_lst)->num == NIL)
				break ;
			(*b_lst) = (*b_lst)->next;
			ft_printf("rb\n");
		}
		(*b_lst) = (*b_lst)->next;
	}
	b_lst_sort_of_less_than_6(a_lst, b_lst, count_lst_struct(*b_lst));
}

void	ft_push_swap(t_stack_list *a_lst, t_stack_list *b_lst)
{	
	while (1)
	{
		if (count_lst_struct(a_lst) < 4)
			a_lst_group_quantity_less_than_6(&a_lst, &b_lst, \
											count_lst_struct(a_lst));
		else
			a_lst_ope(&a_lst, &b_lst);
		b_lst_ope(&a_lst, &b_lst);
		if (a_lst->num == NIL)
			break ;
	}
}
