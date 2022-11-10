/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:54:16 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:19:16 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

/*#include <cplus_flg.h>
#include <stdio.h>
int	main(void)
{
	int c = 'A';
	int ftc = 'A';
	int num = '1';

	printf("%d本家\n",tolower(c));
	printf("%d自作\n\n",ft_tolower(ftc));

	printf("%d本家\n",tolower(num));
	printf("%d自作\n",ft_tolower(num));
}*/
