/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:29:00 by kyamagis          #+#    #+#             */
/*   Updated: 2022/07/29 17:04:53 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int64_t *small, int64_t *big)
{
	int	tmp;

	tmp = *small;
	*small = *big;
	*big = tmp;
}

void	quick_sort(int left, int right, int64_t *sequence)
{
	size_t	i;
	size_t	j;
	int		pivot;

	if (right <= left)
		return ;
	i = left;
	j = right;
	pivot = sequence[(i + j) / 2];
	while (1)
	{
		while (sequence[i] < pivot)
			i++;
		while (pivot < sequence[j])
			j--;
		if (j <= i)
			break ;
		ft_swap(&sequence[j], &sequence[i]);
		i++;
		j--;
	}
	quick_sort(left, i - 1, sequence);
	quick_sort(j + 1, right, sequence);
}
