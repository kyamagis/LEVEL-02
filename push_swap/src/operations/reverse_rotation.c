/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:52:41 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/03 10:48:12 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack_list **a_lst)
{
	*a_lst = (*a_lst)->prev;
	ft_printf("rra\n");
}

void	rrb(t_stack_list **b_lst)
{
	*b_lst = (*b_lst)->prev;
	ft_printf("rrb\n");
}
