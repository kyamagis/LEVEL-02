/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 13:25:17 by kyamagis          #+#    #+#             */
/*   Updated: 2022/08/09 14:16:48 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_countidx(char const *s, char c)
{
	size_t	i;
	size_t	idx;
	char	**strsplit;

	i = 0;
	idx = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0' && s[i] != '\n')
		{
			idx++;
			if (INT_MAX <= idx)
				ft_libft_exit(TOO_MANY_WORDS);
		}	
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	strsplit = (char **)malloc(sizeof(char *) * (idx + 1));
	if (strsplit == NULL)
		ft_libft_exit(MALLOC_ERROR_MESSAGE);
	return (strsplit);
}

static char	**ft_strsplit(char	**strsplit, char const *s, char c)
{
	size_t	len;
	size_t	idx;

	idx = 0;
	while (*s != '\0')
	{
		while ((*s == c || *s == '\n') && *s != '\0')
			s++;
		len = 0;
		while ((*s != c) && (*s != '\0') && (*s != '\n'))
		{
			s++;
			len++;
		}
		if (len != 0)
		{	
			strsplit[idx] = ft_substr(s - len, 0, len);
			if (strsplit[idx] == NULL)
				ft_libft_exit(MALLOC_ERROR_MESSAGE);
			idx++;
		}
	}
	strsplit[idx] = NULL;
	return (strsplit);
}

char	**ft_split(char const *s, char c)
{
	char	**strsplit;

	if (s == NULL)
		return (NULL);
	strsplit = ft_countidx(s, c);
	return (ft_strsplit(strsplit, s, c));
}

/*int	main(void)
{
	char const	s0[] = "//////////hoshi/,//ichigou/sakusen/";
	char	c0 = '/';

	int i = 0;
	while (ft_split(s0, c0)[i] != '\0')
	{
		printf("%s\n", ft_split(s0, c0)[i]);
		i++;
	}
	// char const	s1[] = " hoshi , ichigou sakusen ";
	// char	c1 = ' ';
	printf("%s\n", "+++++++++++++++++++++++++++");
	char const	s2[] = "AAAAAAAAaolol";
	char	c2 = 'A';

	i = 0;
	while (ft_split(s2, c2)[i] != '\0')
	{
		printf("%s\n", ft_split(s2, c2)[i]);
		i++;
	}
	printf("%s\n", "+++++++++++++++++++++++++++");

	char const	s3[] ="      split       this for   me  !       ";
	char	c3 = ' ';

	i = 0;
	char **result = ft_split(s3,c3);
	printf("%d\n",!(!result));
	while (ft_split(s3, c3)[i] != '\0')
	{
		printf("%s\n", ft_split(s3, c3)[i]);
		i++;
	}
	printf("%s\n", ft_split(s3, c3)[i]);
	printf("%s", "+++++++++++++++++++++++++++");
}*/
