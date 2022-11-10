/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:51:28 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/03 10:48:18 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack_list **a_lst)
{
	ft_swap(&(*a_lst)->num, &(*a_lst)->next->num);
	ft_printf("sa\n");
}

void	sb(t_stack_list **b_lst)
{
	ft_swap(&(*b_lst)->num, &(*b_lst)->next->num);
	ft_printf("sb\n");
}
