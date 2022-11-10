/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:08:40 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:19:15 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_exit(char *error_plus_flg)
{
	ft_putendl_fd(error_plus_flg, 2);
	exit(1);
}

static char	**case_of_arg_is_1(char **argv)
{
	char	**numbers;

	numbers = ft_split(argv[1], ' ');
	if (numbers[1] == NULL)
	{
		ft_atoi(numbers[0]);
		exit(0);
	}
	return (numbers);
}

static size_t	count_numbers(char	**numbers)
{
	size_t	i;

	i = 0;
	while (numbers[i] != NULL)
		i++;
	return (i);
}

static void	push_swap_core(size_t quantity, char **argv, int arg_is_one_or_many)
{
	int64_t			*compressed_sequence;
	t_stack_list	a_lst;
	t_stack_list	b_lst;

	compressed_sequence = sequence_compression \
							(quantity, argv, arg_is_one_or_many);
	make_a_lst(&a_lst, quantity, compressed_sequence);
	make_b_lst_nil_node(&b_lst);
	arg_less_than_6(&a_lst, &b_lst, quantity);
	ft_push_swap(&a_lst, &b_lst);
	exit(0);
}

int	main(int argc, char **argv)
{
	char	**numbers;

	if (argc == 1)
		exit(1);
	if (argc == 2)
	{
		numbers = case_of_arg_is_1(argv);
		push_swap_core(count_numbers(numbers), numbers, ARG_IS_ONE);
	}
	else
		push_swap_core(argc - 1, argv, ARG_IS_MANY);
	return (0);
}

/*
__attribute__((destructor))
static void destructor(void)
{
	system("leaks -q push_swap");
}
print_a_lst(&a_lst, a_lst.prev->prev);
void	print_a_lst(t_stack_list *lst_down, t_stack_list *lst_up)
{
	while (lst_down->num != -1)
	{
		printf("%lld ", lst_down->num);
		lst_down = lst_down->next;
	}
	printf("\n");
	
	while (lst_up->num != -1)
	{
		printf("%lld ", lst_up->num);
		lst_up = lst_up->prev;
	}
	printf("\n");
}
*/