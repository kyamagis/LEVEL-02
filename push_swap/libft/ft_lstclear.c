/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyamagis <kyamagis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 18:20:19 by kyamagis          #+#    #+#             */
/*   Updated: 2022/10/03 20:53:50 by kyamagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstnext;

	if ((lst == NULL) || (del == NULL))
		return ;
	while (*lst != NULL)
	{
		lstnext = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = lstnext;
	}
	lst = NULL;
}

/*int main(void)
{
	t_list	*s;
	t_list	*x;
	t_list	*y;
	t_list	*z;


	s = (t_list *)malloc(sizeof(t_list));
	x = (t_list *)malloc(sizeof(t_list));
	y = (t_list *)malloc(sizeof(t_list));
	z = (t_list *)malloc(sizeof(t_list));

	s->next = x;
	x->next = y;
	y->next = z;
	z->next = NULL;

	s->envp_list_content = "EVA-00";
	x->env_content = "EVA-01";
	y->env_content = "EVA-02";
	z->env_content = "EVA-08";

	ft_lstclear(s, del);
	printf("%s\n", (char *)s->envp_list_content);
	printf("%s\n", (char *)x->env_content);
	printf("%s\n", (char *)y->env_content);
	printf("%s\n", (char *)z->env_content);
}*/
