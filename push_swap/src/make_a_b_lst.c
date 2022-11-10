/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_a_b_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:54:42 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/01 14:29:42 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_b_lst_nil_node(t_stack_list *b_lst)
{
	b_lst->num = NIL;
	b_lst->group = NIL;
	b_lst->prev = b_lst;
	b_lst->next = b_lst;
}

void	make_a_lst(t_stack_list *a_lst, \
							size_t quantity, \
							int64_t *compressed_sequence)
{	
	t_stack_list	*tent;
	t_stack_list	*tmp_prev;
	size_t			i;

	tent = a_lst;
	i = 0;
	while (i < quantity)
	{
		tent->num = compressed_sequence[i];
		tent->group = quantity;
		tent->next = (t_stack_list *)malloc(sizeof(t_stack_list));
		if (tent->next == NULL)
			ft_exit(MALLOC_ERROR);
		tmp_prev = tent;
		tent = tent->next;
		tent->prev = tmp_prev;
		i++;
	}
	tent->num = NIL;
	tent->group = NIL;
	tent->next = a_lst;
	a_lst->prev = tent;
}
