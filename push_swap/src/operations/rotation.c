/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:53:27 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/03 10:48:15 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack_list **a_lst)
{
	*a_lst = (*a_lst)->next;
	ft_printf("ra\n");
}

void	rb(t_stack_list **b_lst)
{
	*b_lst = (*b_lst)->next;
	ft_printf("rb\n");
}
