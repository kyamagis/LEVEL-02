/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:16:51 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/04 13:29:25 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	whether_already_sorted(size_t quantity, int64_t *sequence)
{
	size_t		i;
	int64_t		prev_num;

	i = 1;
	prev_num = sequence[0];
	while (i < quantity)
	{
		if (sequence[i] <= prev_num)
			return ;
		prev_num = sequence[i];
		i++;
	}
	exit(1);
}

static int64_t	*a_to_int(size_t quantity, char **argv, int arg_is_one_or_many)
{
	size_t	i;
	int64_t	*sequence;

	sequence = (int64_t *)malloc(sizeof(int64_t) * (quantity));
	if (sequence == NULL)
		ft_exit(MALLOC_ERROR);
	i = 0;
	while (i < quantity)
	{
		sequence[i] = ft_atoi(argv[i + arg_is_one_or_many]);
		i++;
	}
	return (sequence);
}

static void	detect_duplicate_number(size_t quantity, int64_t *sorted_sequence)
{
	size_t	i;

	i = 0;
	while (i + 1 < quantity)
	{
		if (sorted_sequence[i] == sorted_sequence[i + 1])
			ft_exit(ERROR);
		i++;
	}
}

static void	coordinate_compression(size_t quantity, \
									int64_t *sequence, \
									int64_t *sorted_sequence)
{
	size_t	i;
	size_t	compression_num;

	i = 0;
	while (i < quantity)
	{
		compression_num = 0;
		while (1)
		{
			if (sequence[i] == sorted_sequence[compression_num])
			{	
				sequence[i] = (int64_t)compression_num;
				break ;
			}
			compression_num++;
		}
		i++;
	}
}

int64_t	*sequence_compression(size_t quantity, char **argv, \
								int arg_is_one_or_many)
{
	int64_t	*sorted_sequence;
	int64_t	*sequence;

	sorted_sequence = a_to_int(quantity, argv, arg_is_one_or_many);
	whether_already_sorted(quantity, sorted_sequence);
	quick_sort(0, quantity - 1, sorted_sequence);
	detect_duplicate_number(quantity, sorted_sequence);
	sequence = a_to_int(quantity, argv, arg_is_one_or_many);
	coordinate_compression(quantity, sequence, sorted_sequence);
	free (sorted_sequence);
	return (sequence);
}
