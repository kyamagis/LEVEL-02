/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:27:31 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:19:15 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

/*#include <cplus_flg.h>
#include <stdio.h>
int	main(void)
{
	int c = 'a';
	int ftc = 'a';
	int num = '1';

	printf("%d本家\n",toupper(c));
	printf("%d自作\n\n",ft_toupper(ftc));

	printf("%d本家\n",toupper(num));
	printf("%d自作\n",ft_toupper(num));
}*/