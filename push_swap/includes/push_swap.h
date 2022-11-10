/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:27:55 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/11 12:06:57 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define ERROR "Error"
# define MALLOC_ERROR "Error\n"
# define ARG_IS_ONE 0
# define ARG_IS_MANY 1
# define NIL -1
# define SORTED -2

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_stack_list
{
	struct s_stack_list	*prev;
	int64_t				num;
	int64_t				group;
	struct s_stack_list	*next;
}	t_stack_list;

typedef struct s_sequence_max_min
{
	int64_t	max;
	int64_t	min;
}	t_sequence_max_min;

void			ft_exit(char *error_plus_flg);
void			normal_exit(char *operation);
int64_t			*sequence_compression(size_t quantity, char **argv, int arg_is_one_or_many);
void			quick_sort(int left, int right, int64_t *sequence);
void			ft_swap(int64_t *small, int64_t *big);

void			arg_less_than_6(t_stack_list *a_lst, \
								t_stack_list *b_lst, size_t quantity);
void			make_a_lst(t_stack_list *a_lst, \
							size_t quantity, int64_t *compressed_sequence);
void			make_b_lst_nil_node(t_stack_list *b_lst);
void			ft_push_swap(t_stack_list	*a_lst, t_stack_list *b_lst);
void			b_lst_sort_of_less_than_6(t_stack_list **a_lst, \
											t_stack_list **b_lst, \
											int64_t structs_quantity);

int64_t			find_min(t_stack_list *lst);
int64_t			find_max(t_stack_list *lst);
void			a_lst_group_quantity_less_than_6(t_stack_list **a_lst, \
												t_stack_list **b_lst, \
												size_t group_quantity);
void			pb(t_stack_list	**a_lst, t_stack_list **b_lst);
void			pa(t_stack_list	**a_lst, t_stack_list **b_lst);
void			sa(t_stack_list **a_lst);
void			sb(t_stack_list **b_lst);
void			ra(t_stack_list **a_lst);
void			rb(t_stack_list **b_lst);
void			rra(t_stack_list **a_lst);
void			rrb(t_stack_list **b_lst);

#endif
