/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:21:13 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:22:46 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if ((lst == NULL) || (new == NULL))
		return ;
	new->next = *lst;
	*lst = new;
}

/*int 	main(void)
{
	t_list **lst;
	t_list *new;
	
	new = (t_list *)malloc(sizeof(t_list));
	lst = (t_list **)malloc(sizeof(t_list));
	*lst = (t_list *)malloc(sizeof(t_list));
	new->env_content = "try";
	new->next = NULL;
	(*lst)->env_content = "touch down";
	printf("[newenv_content]%s\n", (char *)new->env_content);
	printf("[newnext   ]%d\n", !!(char *)new->next);
	printf("[lstenv_content]%s\n", (char *)(*lst)->env_content);
	printf("[lstnext   ]%d\n", !!(char *)(*lst)->next);
	printf("\n");
	ft_lstadd_front(lst, new);
	printf("[lstenv_content]%s\n", (char *)(*lst)->env_content);
	printf("[lstnext   ]%d\n", !!(char *)(*lst)->next);
}*/
